#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename T, typename merge_t>
struct sparse_table {
    std::vector<std::vector<T>> sparse;
    const merge_t merge;

    sparse_table(const merge_t &merge) : merge(merge) {}
    sparse_table(const std::vector<T> &a, const merge_t &merge) : merge(merge) {
        if (a.empty())
            return;

        int n = int(a.size());
        int lg = std::__lg(n);
        sparse.reserve(lg + 1);
        sparse.push_back(a);

        for (int level = 1; level <= lg; level++) {
            sparse.push_back(std::vector<T>(n - (1 << level) + 1));
            for (int i = 0; i < int(sparse[level].size()); i++)
                sparse[level][i] = merge(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
        }
    }

    T query(int l, int r) const {
        assert(l < r);
        int level = std::__lg(r - l);
        return merge(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

template<typename T>
struct suffix_array {
    std::vector<int> order;
    std::vector<int> suffix_position;
    std::vector<int> lcp;

    suffix_array(T str = T()) {
        str.push_back(*std::min_element(str.begin(), str.end()) - 1);
        int n = str.size();

        order.resize(n);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](const int i, const int j) {
            return str[i] < str[j];
        });

        suffix_position.resize(n);
        for (int i = 0; i < n; i++)
            suffix_position[order[i]] = i == 0 ? 0 : suffix_position[order[i - 1]] + (str[order[i]] != str[order[i - 1]]);

        std::vector<int> ptr(n);
        std::vector<int> new_order(n);
        std::vector<int> new_suffix_positoin(n);

        for (int len = 1; suffix_position[order.back()] != n - 1; len <<= 1) {
            std::fill(ptr.begin(), ptr.begin() + suffix_position[order.back()] + 1, 0);
            for (int i = 0; i < n; i++)
                if (suffix_position[i] + 1 < n)
                    ptr[suffix_position[i] + 1]++;

            for (int i = 1; i <= suffix_position[order.back()]; i++)
                ptr[i] += ptr[i - 1];

            for (const int position : order) {
                int suffix = (position - len + n) % n;
                new_order[ptr[suffix_position[suffix]]++] = suffix;
            }
            std::swap(order, new_order);

            for (int i = 0; i < n; i++)
                new_suffix_positoin[order[i]] = i == 0 ? 0 : new_suffix_positoin[order[i - 1]]
                + (suffix_position[order[i]] != suffix_position[order[i - 1]]
                || suffix_position[(order[i] + len) % n] != suffix_position[(order[i - 1] + len) % n]);

            std::swap(suffix_position, new_suffix_positoin);
        }
        assert(order[0] == n - 1);

        lcp.resize(n);
        int current_lcp = 0;
        for (int suffix = 0; suffix < n - 1; suffix++, current_lcp = current_lcp == 0 ? 0 : current_lcp - 1) {
            int previous_suffix = order[suffix_position[suffix] - 1];
            while (str[suffix + current_lcp] == str[previous_suffix + current_lcp])
                current_lcp++;

            lcp[suffix_position[suffix]] = current_lcp;
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    string s;
    cin >> n >> q >> s;
    suffix_array<string> sa(s);

    auto cmp = [](int x, int y) {
        return x < y ? x : y;
    };
    sparse_table<int, decltype(cmp)> rmq(sa.lcp, cmp);

    while (q--) {
        array<int, 2> sizes;
        cin >> sizes[0] >> sizes[1];

        array<vector<int>, 2> positions;
        for (int j : {0, 1}) {
            positions[j].resize(sizes[j]);
            for (auto &position : positions[j]) {
                cin >> position;
                position = sa.suffix_position[position - 1];
            }
            sort(all(positions[j]));
        }

        ll answer = 0;
        for (int x : positions[0])
            if (binary_search(all(positions[1]), x))
                answer += n - sa.order[x];

        ll sum;
        vector<pair<int, int>> st;
        st.reserve(2 * sizes[0] + sizes[1]);

        auto init = [&]() {
            sum = 0;
            st.clear();
        };

        auto pop_back = [&]() {
            sum -= 1ll * st.back().first * st.back().second;
            st.pop_back();
        };

        auto push_back = [&](const pair<int, int> &x) {
            sum += 1ll * x.first * x.second;
            st.push_back(x);
        };

        auto insert = [&](int x, int cnt) {
            while (!st.empty() && st.back().first >= x) {
                cnt += st.back().second;
                pop_back();
            }
            push_back({x, cnt});
        };

        {
            init();
            for (int i = 0, j = 0; i < sizes[0]; i++) {
                if (j > 0)
                    insert(rmq.query(positions[1][j - 1] + 1, positions[0][i] + 1), 0);

                while (j < sizes[1] && positions[1][j] < positions[0][i])
                    insert(rmq.query(positions[1][j++] + 1, positions[0][i] + 1), 1);

                answer += sum;
            }
        }
        {
            init();
            for (int i = sizes[0] - 1, j = sizes[1] - 1; i >= 0; i--) {
                if (j + 1 < sizes[1])
                    insert(rmq.query(positions[0][i] + 1, positions[1][j + 1] + 1), 0);

                while (j >= 0 && positions[1][j] > positions[0][i])
                    insert(rmq.query(positions[0][i] + 1, positions[1][j--] + 1), 1);

                answer += sum;
            }
        }
        cout << answer << '\n';
    }
}