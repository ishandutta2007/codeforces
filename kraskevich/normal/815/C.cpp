#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = 1000 * 1000 * 1000 + 10;
const int N = 5010;

namespace contest_lib {

template<typename T, size_t N>
class nd_array;

// The nd_array_view structure is used internally to implement the [] operator.
// It doesn't have an assigment operator and all its constructors are private
// because it's not intended for public use.
template<typename T, size_t N, size_t I>
class nd_array_view {
    static_assert(I < N, "The index must be less than the number of dimensions");

public:
    nd_array_view(T* data, const std::array<size_t, N + 2>& dim_products): 
            data(data), dim_products(dim_products) {}

    nd_array_view& operator=(const nd_array_view&) = delete;

    nd_array_view<T, N, I + 1> operator[](size_t index) const {
        return nd_array_view<T, N, I + 1>(data + index * dim_products[I + 2],
                                          dim_products);
    }
    
    template<typename U, size_t M>
    friend class nd_array;
    
    template<typename U, size_t M, size_t J>
    friend class nd_array_view;

private: 
    T* data;
    const std::array<size_t, N + 2>& dim_products;

    nd_array_view(const nd_array_view&) = default;
};

template<typename T, size_t N>
struct nd_array_view<T, N, N> {
public:
    nd_array_view(T* data, const std::array<size_t, N + 2>& dim_products): 
        data(data), length(dim_products.back()) {}

    T& operator[](size_t index) {
        return *(data + index);
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + length;
    }
    
    size_t size() const {
        return length;
    }

    template<typename U, size_t M>
    friend class nd_array;

    template<typename U, size_t M, size_t J>
    friend class nd_array_view;

private:
    T* data;   
    size_t length;
};

// An array view has only three member-function: size, begin and end.
// The latter two are non-const. There's no point in adding const methods to
// it because it's not suppossed to be passed by const reference: it's 
// very light-weight (like a pointer or an interator) and should be passed
// by value and copied whenever necessary.
// The view is bound to the life time of the nd_array it refers to. Using
// it after the parent array is destroyed or invalited is undefined behavior.
// It's guaranteed that all elements of the view are stored in sequential
// order (that is, it's guaranteed that begin and end return standard
// pointers and end - begin == size). The return value of the operator[] 
// is guaranteed to be *(begin + index).
template<typename T, size_t N>
using flat_array_view = nd_array_view<T, N - 2, N - 2>;


// A multidimensional array. Its elements are stored sequentially, so it
// can be more efficient than a vector of vectors or any other nested 
// structure (the precise storage requirements are left up to the
// implementation and are not specified. Relying on a specific storage
// order is undefined behavior).
// Unlike std::array or C-style arrays, its size doesn't have to be known 
// at compile time.
// N must be at least 2.
template<typename T, size_t N>
class nd_array {
    static_assert(N >= 2, "The array must have at least 2 dimensions");

public:
    // Builds an array with the given dimensions. Fills it with the given
    // value.
    // All dimensions must be positive. An std::invalid_argument is thrown
    // otherwise.
    explicit nd_array(const std::array<size_t, N>& dimensions, 
                      const T& value = T()): dimensions(dimensions) {
        if (std::find(dimensions.begin(), dimensions.end(), 0) 
                != dimensions.end()) {
            throw std::invalid_argument("All dimensions must be positive");
        }
        compute_dim_products();
        data.assign(dim_products[0], value);
    }

    nd_array() = default;

    nd_array(const nd_array& other) = default;

    nd_array(nd_array&& other) {
        swap(other);
    }

    nd_array& operator=(const nd_array& other) = default;

    nd_array& operator=(nd_array&& other) {
        swap(other);
        return *this;
    }

    // Returns the dimensions of this array in order they were passed to
    // its constructor.
    std::array<size_t, N> get_dimensions() const {
        return dimensions;
    }

    // Returns an element with index (i1, i2, ..., i_N).
    // Exactly N indices must be provided. Their type should be something
    // int-like (more precisely, it should be possible to cast them to size_t).
    // If at least one of the indices is out of range, the behavior is 
    // undefined.
    // All indices are 0-based.
    T& operator()(const std::array<size_t, N>& indices) {
        return data[get_flat_index(indices)];
    }
    
    const T& operator()(const std::array<size_t, N>& indices) const {
        return data[get_flat_index(indices)];
    }

    template<typename... Indices>
    T& operator()(Indices... indices) {
        static_assert(sizeof...(indices) == N, 
                      "Must have one index for each dimension");
        return data[get_flat_index({{static_cast<size_t>(indices)...}})];
    }
 
    template<typename... Indices>
    const T& operator()(Indices... indices) const {
        static_assert(sizeof...(indices) == N, 
                      "Must have one index for each dimension");
        return data[get_flat_index({{static_cast<size_t>(indices)...}})];
    }

    // The same as the operator(), except that at checks the range of
    // indices at throws an std::out_of_range if at least one of the
    // indices is invalid.
    T& at(const std::array<size_t, N>& indices) {
        check_indices(indices);
        return this->operator()(indices);
    }

    const T& at(const std::array<size_t, N>& indices) const {
        check_indices(indices);
        return this->operator()(indices);
    }

    template<typename... Indices>
    T& at(Indices... indices) {
        static_assert(sizeof...(indices) == N, 
                      "Must have one index for each dimension");
        return at({{static_cast<size_t>(indices)...}});
    }

    template<typename... Indices>
    const T& at(Indices... indices) const {
        static_assert(sizeof...(indices) == N, 
                      "Must have one index for each dimension");
        return at({{static_cast<size_t>(indices)...}});
    }

    // Returns a pair of pointers that correspond to the beginning and the
    // the end of the flat array (i_1, i_2, ..., i_(n - 1), [0, ..., d_n))
    // If at least one of the indices is invalid, the behavior is undefined.
    std::pair<T*, T*> get_flat_subarray(
            const std::array<size_t, N - 1>& indices) {
        size_t start_pos = get_flat_index(to_full_indices(indices));
        return std::make_pair(data.data() + start_pos,
                              data.data() + start_pos + dimensions.back());
    }

    std::pair<const T*, const T*> get_flat_subarray(
            const std::array<size_t, N - 1>& indices) const {
        size_t start_pos = get_flat_index(to_full_indices(indices));
        return std::make_pair(data.data() + start_pos,
                              data.data() + start_pos + dimensions.back());
    }
   
    // The reason for having both get_flat_subarray functions
    // and the [] operator is convenience: if you want to use an array
    // as an index, you use the former. If you want to use a sequence
    // of indices in C-array or std::vector style ([i][j][k]...), you
    // can use the operator[].

    // Returns a pair of pointers that correspond to the beginning and the
    // the end of the flat array (i_1, i_2, ..., i_(n - 1), [0, ..., d_n))
    // Throws an std::out_of_range if the behavior is undefined.
    template<typename... Indices>
    std::pair<T*, T*> get_flat_subarray(Indices... indices) {
        static_assert(sizeof...(indices) == N - 1, 
                      "Must have one index for each dimension except the last");
        return get_flat_subarray({{static_cast<size_t>(indices)...}});
    }
 
    template<typename... Indices>
    std::pair<const T*, const T*> get_flat_subarray(Indices... indices) const {
        static_assert(sizeof...(indices) == N - 1, 
                      "Must have one index for each dimension except the last");
        return get_flat_subarray({{static_cast<size_t>(indices)...}});
    }

    std::pair<T*, T*> get_flat_subarray_safe(
            const std::array<size_t, N - 1>& indices) {
        auto full_indices = to_full_indices(indices);
        check_indices(full_indices);
        size_t start_pos = get_flat_index(full_indices);
        return std::make_pair(data.data() + start_pos,
                              data.data() + start_pos + dimensions.back());
    }

    std::pair<const T*, const T*> get_flat_subarray_safe(
            const std::array<size_t, N - 1>& indices) const {
        auto full_indices = to_full_indices(indices);
        check_indices(full_indices);
        size_t start_pos = get_flat_index(full_indices);
        return std::make_pair(data.data() + start_pos,
                              data.data() + start_pos + dimensions.back());
    }

    template<typename... Indices>
    std::pair<T*, T*> get_flat_subarray_safe(Indices... indices) {
        static_assert(sizeof...(indices) == N - 1, 
                      "Must have one index for each dimension except the last");
        return get_flat_subarray_safe({{static_cast<size_t>(indices)...}});
    }
 
    template<typename... Indices>
    std::pair<const T*, const T*> get_flat_subarray_safe(
            Indices... indices) const {
        static_assert(sizeof...(indices) == N - 1, 
                      "Must have one index for each dimension except the last");
        return get_flat_subarray_safe({{static_cast<size_t>(indices)...}});
    }

    // The [] operator must be applied exactly N or N - 1 times. 
    // You can make the code compile by applying it less times and storing 
    // the result by a const reference, but the behavior of such operation
    // is not specified. 
    // Rationale: Making its behavior well-defined would require either
    // copying a part of underlying storage, making this operator very
    // inefficient, or creating extra requirments on the internal 
    // implementation of this class. Either of these options was deemed
    // undesirable.
    // Note: the object returned as the result of applying this operator 
    // N - 1 times is a view of a flat part of this array. Using the 
    // view after this array is invalidated results in undefined behavior.
    // This operator doesn't check the range of indices. Proving an invalid
    // index is undefined behavior.
    nd_array_view<T, N - 2, 0> operator[](size_t index) {
        return nd_array_view<T, N - 2, 0>(
                data.data() + index * dim_products[1], dim_products);
    }

    nd_array_view<const T, N - 2, 0> operator[](size_t index) const {
        return nd_array_view<const T, N - 2, 0>(
                data.data() + index * dim_products[1], dim_products);
    }

    void swap(nd_array& other) {
        std::swap(data, other.data);
        std::swap(dimensions, other.dimensions);
        std::swap(dim_products, other.dim_products);
    }

private:
    std::array<size_t, N> dimensions = {};
    std::array<size_t, N> dim_products = {};
    std::vector<T> data;

    void compute_dim_products() {
        size_t curr_prod = 1;
        for (int i = static_cast<int>(N) - 1; i >= 0; --i) {
            curr_prod *= dimensions[i];
            dim_products[i] = curr_prod;
        }
    }

    size_t get_flat_index(const std::array<size_t, N>& indices) const {
        size_t flat_index = indices.back();
        for (size_t i = N - 1; i != 0; --i) {
            flat_index += dim_products[i] * indices[i - 1];
        }
        return flat_index;
    }

    void check_indices(const std::array<size_t, N>& indices) const {
        for (size_t i = 0; i < N; ++i) {
            if (indices[i] >= dimensions[i]) {
                throw std::out_of_range("index too large");
            }
        }
    }

    std::array<size_t, N> to_full_indices(
            const std::array<size_t, N - 1>& indices) const { 
        std::array<size_t, N> full_indices;
        std::copy(indices.begin(), indices.end(), full_indices.begin());
        full_indices.back() = 0;
        return full_indices;
    }
};

}

vector<int> g[N];
contest_lib::nd_array<int, 3> dp;
contest_lib::nd_array<int, 2> temp;
int d[N];
int c[N];
int sz[N];

void unite(int v, int t, int s1, int s2) {
    for (int i = 0; i <= s1 + s2; i++)
        temp(i, 0) = temp(i, 1) = INF;
    for (int i = 0; i <= s1; i++)
        for (int j = 0; j <= s2; j++)
            for (int c1 = 0; c1 <= 1; c1++)
                for (int c2 = 0; c2 <= c1; c2++)
                    temp(i + j, c1) = min(temp(i + j, c1), dp(v, i, c1) + dp(t, j, c2));
    for (int i = 0; i <= s1 + s2; i++) {
        dp(v, i, 0) = temp(i, 0);
        dp(v, i, 1) = temp(i, 1);
    }
}

void dfs(int v) {
    sz[v] = 1;
    dp(v, 0, 0) = 0;
    dp(v, 1, 0) = c[v];
    dp(v, 1, 1) = c[v] - d[v];
    for (int to : g[v]) {
        dfs(to);
        unite(v, to, sz[v], sz[to]);
        sz[v] += sz[to];
    }
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    size_t n;
    cin >> n;
    dp = contest_lib::nd_array<int, 3>({n, n + 1, 2}, INF);
    temp = contest_lib::nd_array<int, 2>({n + 1, 2});
    int b;
    cin >> b;
    cin >> c[0] >> d[0];
    for (size_t i = 1; i < n; i++) {
        int x;
        cin >> c[i] >> d[i] >> x;
        --x;
        g[x].push_back(i);
    }
    dfs(0);
    int ans = 0;
    for (size_t i = 0; i <= n; i++)
        if (min(dp(0, i, 0), dp(0, i, 1)) <= b)
            ans = max(ans, (int)i);
    cout << ans << "\n";
}