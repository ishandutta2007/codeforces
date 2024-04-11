/*
    author:  Maksim1744
    created: 09.06.2021 11:03:50
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tl, tr;
    cin >> tl >> tr;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> seg0(n);
    cin >> seg0;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int color = 0;
    vector<int> col(n, -1);
    auto dfs = y_combinator([&](auto dfs, int v, int cc) -> void {
        col[v] = cc;
        for (int k : g[v]) {
            if (col[k] == -1)
                dfs(k, cc ^ 1);
            if (col[v] == col[k]) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    });
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            dfs(i, color);
            color += 2;
        }
    }

    const int inf = 1e9 + 100000;
    vector<pair<int, int>> colseg(color, {0, inf});
    for (int i = 0; i < n; ++i) {
        umax(colseg[col[i]].first, seg0[i].first);
        umin(colseg[col[i]].second, seg0[i].second);
    }

    for (auto [l, r] : colseg) {
        if (l > r) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<pair<pair<int, int>, int>> byl;
    for (int i = 0; i < color; ++i) {
        byl.eb(colseg[i], i);
    }
    sort(byl.begin(), byl.end(), [&](const auto &a, const auto &b) {
        if (a.first.first != b.first.first)
            return a.first.first > b.first.first;
        return a.first.second < b.first.second;
    });
    vector<int> where(color);
    for (int i = 0; i < byl.size(); ++i) {
        where[byl[i].second] = i;
    }

    set<int> left;
    for (int i = 0; i < color; ++i) {
        left.insert(i);
    }

    auto [ll0, rr0] = byl[0].first;
    auto [ll1, rr1] = colseg[byl[0].second ^ 1];
    multiset<int> rmn, rmx;
    rmn.insert(inf);
    rmx.insert(inf);
    for (int i = 0; i < color; i += 2) {
        int r1 = colseg[i].second;
        int r2 = colseg[i ^ 1].second;
        if (r1 > r2) swap(r1, r2);
        rmn.insert(r1);
        rmx.insert(r2);
    }
    auto dl = [&](int i) {
        if (!left.count(i)) return;
        left.erase(i);
        left.erase(i ^ 1);
        int r1 = colseg[i].second;
        int r2 = colseg[i ^ 1].second;
        if (r1 > r2) swap(r1, r2);
        rmn.erase(rmn.find(r1));
        rmx.erase(rmx.find(r2));
    };
    dl(byl[0].second);
    // left.erase(byl[0].second);
    // left.erase(byl[0].second ^ 1);
    show(colseg);
    show(byl);
    for (int i = 1; i < byl.size(); ++i) {
        shows;
        auto [l1, r1] = byl[i].first;
        umax(l1, ll1);
        umin(r1, rr1);
        auto [l0, r0] = mp(ll0, rr0);
        dl(byl[i].second);
        // left.erase(byl[i].second);
        umax(l0, colseg[byl[i].second ^ 1].first);
        umin(r0, colseg[byl[i].second ^ 1].second);
        // left.erase(byl[i].second ^ 1);
        show(l0, r0);
        show(l1, r1);
        bool sw = false;
        if (r0 > r1) {
            sw = true;
            swap(r0, r1);
            swap(l0, l1);
        }

        show(left);
        {
            umin(r0, *rmn.begin());
            umin(r1, *rmx.begin());
            // for (int j = 0; j < colseg.size(); j += 2) {
            //     if (!left.count(j)) continue;
            //     if (colseg[j].second <= colseg[j + 1].second) {
            //         umin(r0, colseg[j].second);
            //         umin(r1, colseg[j + 1].second);
            //     } else {
            //         umin(r1, colseg[j].second);
            //         umin(r0, colseg[j + 1].second);
            //     }
            // }
        }
        show(l0, r0);
        show(l1, r1);
        if (l0 <= r0 && l1 <= r1) {
            int n0 = l0;
            int n1 = l1;
            n0 += min(r0 - l0, tr - (n0 + n1));
            n1 += min(r1 - l1, tr - (n0 + n1));
            if (l0 <= n0 && n0 <= r0 && l1 <= n1 && n1 <= r1 && tl <= n0 + n1 && n0 + n1 <= tr) {
                cout << "POSSIBLE\n";

                vector<int> colgroup(color);
                for (int j = 0; j < i; ++j) {
                    colgroup[byl[j].second] = 1;
                    colgroup[byl[j].second ^ 1] = 2;
                }
                show(colgroup);
                colgroup[byl[i].second] = 2;
                colgroup[byl[i].second ^ 1] = 1;
                show(colgroup);
                int c1 = 1, c2 = 2;
                if (sw) {
                    swap(c1, c2);
                    swap(n0, n1);
                }

                for (int j = 0; j < colseg.size(); j += 2) {
                    if (!left.count(j)) continue;
                    if (colseg[j].second <= colseg[j + 1].second) {
                        colgroup[j] = c1;
                        colgroup[j + 1] = c2;
                    } else {
                        colgroup[j] = c2;
                        colgroup[j + 1] = c1;
                    }
                }

                show(colgroup);
                cout << n0 << ' ' << n1 << '\n';
                for (int i = 0; i < n; ++i) {
                    cout << colgroup[col[i]];
                }
                cout << '\n';

                return 0;
            } else {
                assert(tr < l0 + l1 || tl > r0 + r1);
            }
        }

        {
            auto [l, r] = byl[i].first;
            umax(ll0, l);
            umin(rr0, r);
        }
        if (where[byl[i].second ^ 1] < i) {
            break;
        }
        {
            auto [l, r] = colseg[byl[i].second ^ 1];
            umax(ll1, l);
            umin(rr1, r);
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}