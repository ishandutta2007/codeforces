/*
    author:  Maksim1744
    created: 29.08.2021 18:02:04
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1, -1);

    vector<int> a_ = {0, 5, 8, 13, 9, 1293871, 47832};

    auto ask_and = [&](int i, int j) {
        cout << "and " << i << ' ' << j << endl;
        // return a_[i] & a_[j];
        int a;
        cin >> a;
        return a;
    };
    auto ask_or = [&](int i, int j) {
        cout << "or " << i << ' ' << j << endl;
        // return a_[i] | a_[j];
        int a;
        cin >> a;
        return a;
    };

    auto solve = [&](vector<int> inds) {
        int n = inds.size();
        vector<int> ands;
        for (int i = 0; i < n; ++i) {
            ands.pb(ask_and(inds[i], inds[(i + 1) % n]));
        }
        if (inds.size() == 4) {
            vector<pair<int, int>> que;
            que.eb(0, 1);
            que.eb(1, 3);
            que.eb(3, 2);
            que.eb(2, 0);
            vector<int> ors;
            for (auto [a, b] : que) {
                ors.pb(ask_or(inds[a], inds[b]));
            }
            for (int i : inds)
                a[i] = 0;
            for (int b = 0; b < 30; ++b) {
                for (int mask = 0; mask < 16; ++mask) {
                    vector<int> vv;
                    for (int k = 0; k < 4; ++k) {
                        vv.pb((mask >> k) & 1);
                    }
                    vector<int> mands, mors;
                    for (int k = 0; k < 4; ++k) {
                        mands.pb(vv[k] & vv[(k + 1) % 4]);
                        mors.pb(vv[que[k].first] | vv[que[k].second]);
                    }
                    bool ok = true;
                    for (int i = 0; i < 4; ++i) {
                        if (((ands[i] >> b) & 1) != mands[i]) ok = false;
                        if (((ors[i] >> b) & 1) != mors[i]) ok = false;
                    }
                    if (ok) {
                        for (int u = 0; u < 4; ++u) {
                            a[inds[u]] |= (vv[u] << b);
                        }
                        break;
                    }
                }
            }
            return;
        } else {
            vector<int> ors;
            for (int i = 0; i < n; ++i) {
                ors.pb(ask_or(inds[i], inds[(i + 1) % n]));
            }
            for (int k : inds)
                a[k] = 0;

            for (int b = 0; b < 30; ++b) {
                bool found = false;
                for (int i = 0; i < n; ++i) {
                    if (((ors[i] >> b) & 1) == 0 || ((ands[i] >> b) & 1) == 1) {
                        found = true;
                        vector<int> v(n);
                        if (((ors[i] >> b) & 1) == 0) v[i] = v[(i + 1) % n] = 0;
                        else v[i] = v[(i + 1) % n] = 1;
                        for (int j = (i + 2) % n; j != i; j = (j + 1) % n) {
                            int prev = v[(j - 1 + n) % n];
                            if (prev == 1) v[j] = ((ands[(j - 1 + n) % n] >> b) & 1);
                            else v[j] = ((ors[(j - 1 + n) % n] >> b) & 1);
                        }
                        show(b, ors, ands, v);
                        for (int k = 0; k < n; ++k) {
                            a[inds[k]] |= (v[k] << b);
                        }

                        break;
                    }
                }
                assert(found);
            }
        }
    };

    if (n % 2 == 1 || n == 4) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        solve(v);
    } else {
        vector<int> v(n - 3);
        iota(v.begin(), v.end(), 4);
        solve(v);
        solve({1, 2, 3});
    }

    show(a);
    sort(a.begin() + 1, a.end());
    cout << "finish " << a[k] << endl;

    return 0;
}