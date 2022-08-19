/*
    author:  Maksim1744
    created: 11.12.2021 13:37:58
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;
    int K;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
        K = 0;
        while ((1 << K) <= n)
            ++K;
    }

    void clear() {
        tree.assign(n, 0);
    }

    void add(int i, T k) {
        for (; i < n; i = (i | (i + 1)))
            tree[i] += k;
    }

    T ask(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += tree[r];
        return res;
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(r) - ask(l - 1);
    }
 
    // smallest ind such that sum[0..ind] >= v
    int find_ind(int v) {
        int cur = 0;
        int cur_sum = 0;
        for (int k = K - 1; k >= 0; --k) {
            int ind = cur | ((1 << k) - 1);
            if (ind >= n) continue;
            if (cur_sum + tree[ind] >= v) continue;
            cur_sum += tree[ind];
            cur |= (1 << k);
        }
        return cur;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    cin >> v;
    for (int i = 0; i < n; ++i) {
        v[i].second--;
    }

    int K = 0;

    for (int its = 0; its < 2; ++its) {
        for (auto& [p, c] : v) {
            swap(p.first, p.second);
        }

        vector<int> x, y;
        for (auto [p, c] : v) {
            x.pb(p.first);
            y.pb(p.second);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());

        for (auto& [p, c] : v) {
            p.first = lowb(x, p.first);
            p.second = lowb(y, p.second);
        }

        vector<int> p = {0, 1, 2};

        auto v0 = v;

        do {
            auto v = v0;
            for (int i = 0; i < n; ++i) {
                v[i].second = p[v[i].second];
            }
            // 0, 1, 2 in a line
            {
                int L = 0;
                int R = n / 3 + 1;

                sort(v.begin(), v.end(), [&](const auto& a, const auto& b) {
                    if (a.first.first != b.first.first) return a.first.first < b.first.first;
                    return a.second > b.second;
                });

                while (R - L > 1) {
                    int C = (L + R) / 2;

                    int ind = 0;
                    bool ok = true;
                    for (int i = 0; i < 3; ++i) {
                        int cnt = 0;
                        while (ind < n && cnt < C) {
                            if (v[ind].second == i) ++cnt;
                            ++ind;
                        }
                        if (cnt != C) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                        L = C;
                    else
                        R = C;
                }

                K = max(K, L);
            }

            for (int it2 = 0; it2 < 2; ++it2) {
                for (auto& [p, c] : v)
                    p.second = y.size() - 1 - p.second;

                sort(v.begin(), v.end(), [&](const auto& a, const auto& b) {
                    if (a.first.first != b.first.first) return a.first.first < b.first.first;
                    return a.second > b.second;
                });

                vector<int> at_least(y.size() + 1, 0);
                for (auto& [p, c] : v)
                    if (c == 2)
                        at_least[p.second]++;
                for (int i = (int)at_least.size() - 2; i >= 0; --i)
                    at_least[i] += at_least[i + 1];

                fenwick<int> f1(y.size()), f2(y.size());

                int L = 0, R = n / 3 + 1;
                while (R - L > 1) {
                    int C = (L + R) / 2;

                    f1.clear();
                    f2.clear();

                    for (int i = 0; i < n; ++i) {
                        if (v[i].second == 1)
                            f2.add(v[i].first.second, 1);
                    }
                    bool ok = false;
                    for (int i = 0; i < n; ++i) {
                        if (v[i].second == 0) {
                            f1.add(v[i].first.second, 1);
                        } else if (v[i].second == 1) {
                            f2.add(v[i].first.second, -1);
                        }

                        if (f1.ask(y.size() - 1) >= C && f2.ask(y.size() - 1) >= C) {
                            int y = max(f1.find_ind(C), f2.find_ind(C));
                            if (at_least[y + 1] >= C) {
                                show(C, i, y);
                                ok = true;
                                break;
                            }
                        }
                    }

                    if (ok) {
                        L = C;
                    } else {
                        R = C;
                    }
                }

                show(v, L);

                K = max(K, L);
            }
        } while (next_permutation(p.begin(), p.end()));
    }


    cout << K * 3 << '\n';

    return 0;
}