// Built using contest lib
// Actual solution is at the bottom

#include <bits/stdc++.h>



namespace contest_lib {

template<typename T>
class coordinate_compressor {
public:
    coordinate_compressor() = default;

    template<typename It>
    coordinate_compressor(It begin, It end): values(begin, end) {
        compress();
    }

    int size() const {
        return values.size();
    }
 
    int get_compressed(const T& value) const {
        return std::lower_bound(values.begin(), values.end(), value) 
            - values.begin();
    }

    T get_original(int index) const {
        return values[index];
    }

private:
    void compress() {
        std::sort(values.begin(), values.end());
        values.resize(std::unique(values.begin(), values.end()) 
                - values.begin());
    }

    std::vector<T> values;
};

}


namespace contest_lib { namespace algorithms {

template<typename X, typename Y>
struct point {
    X x = {};
    Y y = {};

    point() = default;

    constexpr point(X x, Y y): x(x), y(y) {}
};

template<typename X, typename Y>
struct rectangle {
    point<X, Y> low;
    point<X, Y> high;

    constexpr rectangle(const point<X, Y>& low, const point<X, Y>& high): 
        low(low), high(high) {}
};

}
}


namespace contest_lib {

template<typename T>
class binary_index_tree {
public:
    explicit binary_index_tree(int size = 0) {
        if (size < 0) {
            throw std::invalid_argument("The size must be non-negative");
        }
        cummulative_sums.resize(size);
    }

    int size() const {
        return cummulative_sums.size();    
    }

    void add(int pos, T modifier) {
        for (; pos < static_cast<int>(cummulative_sums.size()); 
                pos = (pos | (pos + 1))) {
            cummulative_sums[pos] += modifier;
        }
    }

    T get(int pos) const {
        T res = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            res += cummulative_sums[pos];
        }
        return res;
    }

    T get(int left, int right) const {
        return get(right) - get(left - 1);
    }

private:
    std::vector<T> cummulative_sums;
};

}



namespace contest_lib { namespace algorithms {

namespace count_points_in_2d_rectangle_details {
    enum class event_type {
        SUBTRACT_ANSWER = -1,
        ADD_POINT = 0,
        ADD_ANSWER = 1
    };

    template<typename X, typename Y>
    struct event {
        event_type type;
        X x;
        Y low_y;
        Y high_y;
        int id;

        event(event_type type, X x, Y low_y, Y high_y, int id = -1): 
            type(type), x(x), low_y(low_y), high_y(high_y), id(id) {}
    
        bool operator<(const event& rhs) const {
            if (x != rhs.x) {
                return x < rhs.x;
            }
            return type < rhs.type;
        }
    };

    template<typename X, typename Y>
    std::vector<event<X, Y>> generate_events(
            const std::vector<point<X, Y>>& points,
            const std::vector<rectangle<X, Y>>& rectangles) {
        std::vector<event<X, Y>> events;
        events.reserve(points.size() + 2 * rectangles.size());
        std::transform(points.begin(), points.end(), 
                       std::back_inserter(events), [](const auto& point) { 
                            return event<X, Y>(event_type::ADD_POINT, point.x,
                                         point.y, point.y); 
                            });
        for (size_t i = 0; i < rectangles.size(); ++i) {
            const auto& rectangle = rectangles[i];
            events.push_back(event<X, Y>(event_type::SUBTRACT_ANSWER, 
                                         rectangle.low.x, rectangle.low.y, 
                                         rectangle.high.y, i));
            events.push_back(event<X, Y>(event_type::ADD_ANSWER, 
                                         rectangle.high.x, rectangle.low.y, 
                                         rectangle.high.y, i)); 
        }
        return events;
    }

    template<typename X, typename Y>
    std::vector<Y> generate_all_ys(
            const std::vector<point<X, Y>>& points,
            const std::vector<rectangle<X, Y>>& rectangles) {
        std::vector<Y> all_ys;
        all_ys.reserve(points.size() + 2 * rectangles.size());
        std::transform(points.begin(), points.end(), 
                       std::back_inserter(all_ys),
                       [](const auto& point) { return point.y; });
        for (const auto& rectangle : rectangles) {
           all_ys.push_back(rectangle.low.y);
           all_ys.push_back(rectangle.high.y);
        }
        return all_ys;
    }
}

template<typename X, typename Y>
std::vector<int> count_points_in_rectangles(
        const std::vector<point<X, Y>>& points,
        const std::vector<rectangle<X, Y>>& rectangles) {
    using count_points_in_2d_rectangle_details::event_type;
    using count_points_in_2d_rectangle_details::generate_events;
    using count_points_in_2d_rectangle_details::generate_all_ys;

    auto all_ys = generate_all_ys(points, rectangles);
    coordinate_compressor<Y> compressor(all_ys.begin(), all_ys.end());
    auto events = generate_events(points, rectangles);
    sort(events.begin(), events.end());
    std::vector<int> result(rectangles.size());
    binary_index_tree<int> tree(compressor.size());
    for (const auto& event : events) {
        if (event.type == event_type::ADD_POINT) {
            int y = compressor.get_compressed(event.low_y);
            tree.add(y, 1);
        } else {
            int sign = static_cast<int>(event.type);
            int low_y = compressor.get_compressed(event.low_y);
            int high_y = compressor.get_compressed(event.high_y);
            result[event.id] += sign * tree.get(low_y, high_y);
        }
    }
    return result;
}
   
}
}


namespace contest_lib {

class tree_policy_base {
public:
    tree_policy_base(const std::vector<std::vector<int>>& graph): 
            graph(graph), 
            is_deleted(graph.size()), 
            root(graph.size()), 
            size(graph.size()),
            max_size(graph.size()) {}

protected:
    std::vector<std::vector<int>> graph;
    std::vector<bool> is_deleted;
    std::vector<int> root;
    std::vector<int> size;
    std::vector<int> max_size;
    std::vector<int> visited_list;    
};

template<typename TreePolicy>
class centroid_decomposition : TreePolicy {
    using TreePolicy::graph;
    using TreePolicy::is_deleted;
    using TreePolicy::root;
    using TreePolicy::size;
    using TreePolicy::max_size;
    using TreePolicy::visited_list;
    // This function should take an int and a vector of int (a centroid
    // and the current subtree) and performs problem-specific computations.
    using TreePolicy::process_subtree;
    // get_result accumulates the result over all parts of decomposition
    // and return it (it can be anything).
    using TreePolicy::get_result;

public:
    template<typename... Args>
    centroid_decomposition(Args... args): 
            TreePolicy(std::forward<Args>(args)...) {}

    auto get_result(int start_vertex = 0) {
        solve(start_vertex);
        return TreePolicy::get_result();
    }
    
private:
    void dfs_compute_size(int v, int parent) {
        visited_list.push_back(v);
        size[v] = 1;
        max_size[v] = 0;
        for (int to : graph[v]) {
            if (to != parent && !is_deleted[to]) {
                dfs_compute_size(to, v);
                size[v] += size[to];
                max_size[v] = std::max(max_size[v], size[to]);
            }
        }
    }
    
    void dfs_compute_root(int v, int curr_root, int parent) {
        root[v] = curr_root;
        for (int to : graph[v]) {
            if (to != parent && !is_deleted[to]) {
                dfs_compute_root(to, curr_root, v);
            }
        }
    }
    
    void solve(int start_vertex) {
        dfs_compute_size(start_vertex, start_vertex);
        auto current_subtree = visited_list;
        visited_list.clear();
        int centroid = -1;
        for (int vertex : current_subtree) {
            int max_subtree_size = std::max(
                    static_cast<int>(current_subtree.size()) - size[vertex], 
                    max_size[vertex]);
            if (2 * max_subtree_size 
                    <= static_cast<int>(current_subtree.size())) {
                centroid = vertex;
            }
        }
        assert(centroid != -1);
        is_deleted[centroid] = true;
        for (int child : graph[centroid])
            if (!is_deleted[child]) {
                solve(child);
                dfs_compute_root(child, child, child);
            }
        root[centroid] = centroid;
        is_deleted[centroid] = false;
        process_subtree(centroid, current_subtree);
    } 
};

}



namespace contest_lib { namespace math {

template<typename T, typename U>
constexpr T bin_pow(T base, U pow) {
    T result = T::unit(base);
    for (; pow > 0; pow /= 2) {
        if (pow % 2 == 1) {
            result *= base;
        }
        base *= base;
    }
    return result;
}

template<typename T, T MOD>
struct fixed_mod_number {
    T value;

    explicit constexpr fixed_mod_number(const T& value = 0): value(value) {
        this->value %= MOD;
        if (this->value < 0) {
            this->value += MOD;
        }
    }

    static constexpr fixed_mod_number unit(const fixed_mod_number&) {
        return fixed_mod_number(1);
    }

    constexpr fixed_mod_number& operator+=(const fixed_mod_number& rhs) {
        value += rhs.value;
        if (value >= MOD) {
            value -= MOD;
        }
        return *this;
    }

    constexpr fixed_mod_number& operator-=(const fixed_mod_number& rhs) {
        value -= rhs.value;
        if (value < 0) {
            value += MOD;
        }
        return *this;
    }

    constexpr fixed_mod_number& operator*=(const fixed_mod_number& rhs) {
        value *= rhs.value;
        value %= MOD;
        return *this;
    }

    constexpr fixed_mod_number& operator/=(const fixed_mod_number& rhs) {
        assert (rhs.value != 0);
        *this *= bin_pow(rhs, MOD - 2);
        return *this;
    }

    constexpr fixed_mod_number operator+(const fixed_mod_number& rhs) const {
        auto result(*this);
        result += rhs;
        return result;
    }

    constexpr fixed_mod_number operator-(const fixed_mod_number& rhs) const {
        auto result(*this);
        result -= rhs;
        return result;
    }

    constexpr fixed_mod_number operator*(const fixed_mod_number& rhs) const {
        auto result(*this);
        result *= rhs;
        return result;
    }

    constexpr fixed_mod_number operator/(const fixed_mod_number& rhs) const {
        auto result(*this);
        result /= rhs;
        return result;
    }

    constexpr bool operator==(const fixed_mod_number& rhs) const {
        return value == rhs.value;
    }
};

template<typename T>
struct mod_number {
    T value;
    T mod;

    explicit constexpr mod_number(const T& value = 0, const T& mod = 0): 
            value(value), mod(mod) {
        this->value %= mod;
        if (this->value < 0) {
            this->value += mod;
        }
    }

    static constexpr mod_number unit(const mod_number& base) {
        return mod_number(1, base.mod);
    }

    constexpr mod_number& operator+=(const mod_number& rhs) {
        value += rhs.value;
        if (value >= mod) {
            value -= mod;
        }
        return *this;
    }

    constexpr mod_number& operator-=(const mod_number& rhs) {
        value -= rhs.value;
        if (value < 0) {
            value += mod;
        }
        return *this;
    }

    constexpr mod_number& operator*=(const mod_number& rhs) {
        value *= rhs.value;
        value %= mod;
        return *this;
    }

    constexpr mod_number& operator/=(const mod_number& rhs) {
        assert (rhs.value != 0);
        *this *= bin_pow(rhs, mod - 2);
        return *this;
    }

    constexpr mod_number operator+(const mod_number& rhs) const {
        auto result(*this);
        result += rhs;
        return result;
    }

    constexpr mod_number operator-(const mod_number& rhs) const {
        auto result(*this);
        result -= rhs;
        return result;
    }

    constexpr mod_number operator*(const mod_number& rhs) const {
        auto result(*this);
        result *= rhs;
        return result;
    }

    constexpr mod_number operator/(const mod_number& rhs) const {
        auto result(*this);
        result /= rhs;
        return result;
    }

    constexpr bool operator==(const mod_number& rhs) const {
        return value == rhs.value;
    }
};

}
}

using namespace std;

using ll = long long;

constexpr ll MOD = (ll)1000 * 1000 * 1000 + 7;
constexpr int INF = 1000 * 1000 * 1000;

using contest_lib::tree_policy_base;
using contest_lib::centroid_decomposition;
using contest_lib::algorithms::count_points_in_rectangles;
using point = contest_lib::algorithms::point<int, int>;
using rectangle = contest_lib::algorithms::rectangle<int, int>;
using number = contest_lib::math::fixed_mod_number<ll, MOD>;

struct tree : tree_policy_base {
    vector<vector<number>> w;
    vector<vector<int>> col;
    vector<int> h0;
    vector<int> h1;
    vector<number> func;
    number ans{1};

    tree(const vector<vector<int>>& graph, const vector<vector<number>>& w, 
            const vector<vector<int>>& col): 
        tree_policy_base(graph), 
        w(w), 
        col(col), 
        h0(graph.size()), 
        h1(graph.size()),
        func(graph.size()) {}

    void dfs_calc(int v, int p, int hh0, int hh1, number prod) {
        func[v] = prod;
        h0[v] = hh0;
        h1[v] = hh1;
        func[v] = prod;
        for (int i = 0; i < (int)graph[v].size(); ++i) {
            if (graph[v][i] == p || is_deleted[graph[v][i]])
                continue;
            dfs_calc(graph[v][i], v, hh0 + (col[v][i] == 0), 
                     hh1 + (col[v][i] == 1), prod * w[v][i]);
        }
    }

    void process_subtree(int v, const vector<int>& all) {
        dfs_calc(v, v, 0, 0, number(1));
        map<int, vector<point>> for_root_pt;
        map<int, vector<rectangle>> for_root_rect;
        map<int, vector<number>> for_root_fs; 
        vector<point> points;
        vector<rectangle> rectangles;
        vector<number> fs;
        static constexpr point INF_PT{-INF, -INF};
        for (auto x : all) {
            point cur_pt(h0[x] - 2 * h1[x], h1[x] - 2 * h0[x]);
            point neg_pt(-cur_pt.x, -cur_pt.y);
            for_root_pt[root[x]].push_back(cur_pt);
            points.push_back(cur_pt);
            for_root_rect[root[x]].emplace_back(INF_PT, neg_pt);
            rectangles.emplace_back(INF_PT, neg_pt);
            for_root_fs[root[x]].push_back(func[x]);
            fs.push_back(func[x]);
        }
        for (auto& q : for_root_pt) {
            int r = q.first;
            auto& funcs = for_root_fs[r];
            auto cnts = count_points_in_rectangles(for_root_pt[r],
                                                   for_root_rect[r]);
            for (int i = 0; i < (int)funcs.size(); ++i) {
                ans /= contest_lib::math::bin_pow(funcs[i], cnts[i]);
            }
        }
        auto cnts = count_points_in_rectangles(points, rectangles);
        for (int i = 0; i < (int)fs.size(); ++i) {
            ans *= contest_lib::math::bin_pow(fs[i], cnts[i]);
        }
    }

    int get_result() const {
        return ans.value;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<vector<number>> w(n);
    vector<vector<int>> col(n);
    for (int i = 0; i < n - 1; i++) {
         int a, b, x, c;
         cin >> a >> b >> x >> c;
         --a;
         --b;
         g[a].push_back(b);
         g[b].push_back(a);
         w[a].push_back(number(x));
         w[b].push_back(number(x));
         col[a].push_back(c);
         col[b].push_back(c);
    }
    centroid_decomposition<tree> d(g, w, col);
    cout << d.get_result() << "\n";
}