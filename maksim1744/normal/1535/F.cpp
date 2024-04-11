/*
    author:  Maksim1744
    created: 04.06.2021 18:19:42
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    cin >> v;
    const int B = 1e4;
    // const int B = 0;
    // #warning todo

    sort(v.begin(), v.end());

    map<string, vector<string>> byset;
    for (int i = 0; i < n; ++i) {
        string t = v[i];
        sort(t.begin(), t.end());
        byset[t].pb(v[i]);
    }

    ll bad = (ll)n * (n - 1) / 2;
    for (auto &[a, b] : byset) {
        ll x = b.size();
        bad -= x * (x - 1) / 2;
    }

    auto solve = [&](vector<string> v) -> ll {
        int n = v.size();
        if (n <= 1) {
            return 0;
        }
        if (n <= B) {
            vector<pair<string, int>> v1(n), v2(n);
            for (int i = 0; i < n; ++i) {
                v1[i].first = v2[i].first = v[i];
                v1[i].second = v2[i].second = i;
                reverse(v2[i].first.begin(), v2[i].first.end());
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            auto build_lcp = [&](const vector<pair<string, int>> &v) {
                vector<int> lcp(v.size() - 1);
                for (int i = 0; i + 1 < v.size(); ++i) {
                    int ln = 0;
                    while (v[i].first[ln] == v[i + 1].first[ln])
                        ++ln;
                    lcp[i] = ln;
                }
                return lcp;
            };
            auto lcp1 = build_lcp(v1);
            auto lcp2 = build_lcp(v2);
            auto build_sparse = [&](const vector<int> &v) {
                int b = 0;
                while ((1 << b) <= n)
                    ++b;
                ++b;
                vector<vector<int>> res(b, vector<int>(v.size()));
                res[0] = v;
                for (int i = 1; i < res.size(); ++i) {
                    for (int j = 0; j + (1 << i) <= v.size(); ++j) {
                        res[i][j] = min(res[i - 1][j], res[i - 1][j + (1 << (i - 1))]);
                    }
                }
                return res;
            };
            vector<int> p2(n + 2);
            p2[1] = 0;
            for (int i = 2; i < p2.size(); ++i)
                p2[i] = p2[i / 2] + 1;
            auto sparse1 = build_sparse(lcp1);
            auto sparse2 = build_sparse(lcp2);

            show(sparse1);
            show(sparse2);

            vector<int> where1(n), where2(n);
            for (int i = 0; i < n; ++i) {
                where1[v1[i].second] = i;
                where2[v2[i].second] = i;
            }

            show(p2);

            auto ask_sparse = [&](const vector<vector<int>> &v, int l, int r) {
                if (l > r) swap(l, r);
                --r;
                assert(l <= r);
                int ln = p2[r - l + 1];
                show(l, r, ln);
                return min(v[ln][l], v[ln][r - (1 << ln) + 1]);
            };

            vector<vector<int>> sorted_until(n);
            for (int i = 0; i < n; ++i) {
                sorted_until[i].resize(v[i].size());
                sorted_until[i].back() = v[i].size() - 1;
                for (int j = (int)v[i].size() - 2; j >= 0; --j) {
                    if (v[i][j] <= v[i][j + 1])
                        sorted_until[i][j] = sorted_until[i][j + 1];
                    else
                        sorted_until[i][j] = j;
                }
            }

            show(sorted_until);
            show(where1);
            show(where2);
            show(v1);
            show(v2);
            show(lcp1);
            show(lcp2);

            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    auto lpref = ask_sparse(sparse1, where1[i], where1[j]);
                    auto lsuf = ask_sparse(sparse2, where2[i], where2[j]);
                    int L = lpref;
                    int R = v[i].size() - lsuf - 1;
                    show(v);
                    show(lpref, lsuf);
                    show(v[i], v[j], L, R);
                    if (sorted_until[i][L] >= R || sorted_until[j][L] >= R)
                        ans += 1;
                    else
                        ans += 2;
                }
            }
            return ans;
        } else {
            int k = v[0].size();
            sort(v.begin(), v.end());

            struct Node {
                map<char, int> to;
                int sm = 0;
            };
            vector<Node> nodes;
            auto new_node = [&]() {
                nodes.eb();
                return (int)nodes.size() - 1;
            };

            ll ans = 0;
            auto solve2 = [&](const vector<string> &v) {
                show(v, ans);
                vector<vector<int>> by_last_let;
                for (int i = 0; i < v.size(); ++i) {
                    if (by_last_let.empty() || v[i][0] != v[i - 1][0]) {
                        by_last_let.eb();
                    }
                    by_last_let.back().pb(i);
                }
                for (int u = 0; u + 1 < by_last_let.size(); ++u) {
                    nodes.clear();
                    nodes.eb();
                    for (int i : by_last_let[u]) {
                        int j = 1;
                        while (j < v[i].size() && v[i][j] >= v[i][j - 1])
                            ++j;
                        string t = v[i].substr(j, v[i].size());
                        reverse(t.begin(), t.end());
                        int node = 0;
                        for (char c : t) {
                            if (!nodes[node].to.count(c))
                                nodes[node].to[c] = new_node();
                            node = nodes[node].to[c];
                        }
                        nodes[node].sm++;
                    }
                    for (int x = u + 1; x < by_last_let.size(); ++x) {
                        for (int i : by_last_let[x]) {
                            int node = 0;
                            ans += nodes[node].sm;
                            int done = by_last_let[u].size();
                            done -= nodes[node].sm;
                            for (int j = (int)v[i].size() - 1; j >= 0; --j) {
                                char c = v[i][j];
                                if (!nodes[node].to.count(c)) break;
                                node = nodes[node].to[c];
                                ans += nodes[node].sm;
                                done -= nodes[node].sm;
                            }
                            ans += done * 2;
                        }
                    }
                }
                show(ans);
            };

            for (int lpref = 0; lpref < k; ++lpref) {
                vector<string> cur;
                auto get_suf = [&](const string &s) {
                    return s.substr(lpref, s.size());
                    // string t = s.substr(lpref, s.size());
                    // reverse(t.begin(), t.end());
                    // return t;
                };
                cur.pb(get_suf(v[0]));
                for (int i = 1; i < v.size(); ++i) {
                    bool ok = true;
                    for (int j = 0; j < lpref; ++j) {
                        if (v[i][j] != v[i - 1][j]) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        solve2(cur);
                        cur.clear();
                    }
                    cur.pb(get_suf(v[i]));
                }
                solve2(cur);
            }
            return ans;
        }
    };

    ll ans = 0;
    for (auto &[a, b] : byset)
        ans += solve(b);

    show(ans);

    cout << ans + bad * 1337 << '\n';

    return 0;
}