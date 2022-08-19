/*
    author:  Maksim1744
    created: 22.08.2021 16:10:59
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

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n - 1);
    cin >> a;
    a.insert(a.begin(), 0);
    vector<int> b(n - 1);
    cin >> b;
    b.insert(b.begin(), 0);

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    show(a);
    show(b);
    show(g);

    auto can = [&](ll hp) {
        vector<int> done = {0};
        vector<bool> is_done(n, false); is_done[0] = true;
        vector<bool> u(n, false);
        vector<ll> pw(n);
        vector<int> par(n, -1);
        while (done.size() != n) {
            if (hp == 12) show(done);
            queue<int> q;
            pw.assign(n, 0);
            u.assign(n, false);
            par.assign(n, -1);

            for (int k : done) {
                q.push(k);
                u[k] = true;
                pw[k] = hp;
            }

            bool found = false;

            auto trace = [&](int v, int k) {
                found = true;
                vector<int> path;
                int v0 = v;
                while (!is_done[v0]) {
                    path.pb(v0);
                    v0 = par[v0];
                }
                reverse(path.begin(), path.end());
                v0 = k;
                while (!is_done[v0]) {
                    path.pb(v0);
                    v0 = par[v0];
                }
                assert(!path.empty());
                if (hp == 12) show(v, k, path, par);
                for (int x : path) {
                    if (!is_done[x]) {
                        done.pb(x);
                        is_done[x] = true;
                        hp += b[x];
                    }
                }
            };

            while (!q.empty() && !found) {
                int v = q.front();
                q.pop();

                for (int k : g[v]) {
                    if (is_done[v] && is_done[k]) continue;
                    if (k == par[v]) continue;
                    if (u[k]) {
                        // back;
                        trace(v, k);
                        break;
                    } else if (pw[v] > a[k]) {
                        par[k] = v;
                        pw[k] = pw[v] + b[k];
                        u[k] = true;
                        q.push(k);
                    }
                }
            }

            // if (!found) {
            //     for (int i = 0; i < n; ++i) {
            //         if (!u[i]) continue;
            //         for (int j : g[i]) {
            //             if (is_done[i] && is_done[j]) continue;
            //             if (!u[j]) continue;
            //             if (par[i] != j && par[j] != i) {
            //                 trace(i, j);
            //                 break;
            //             }
            //         }
            //         if (found) break;
            //     }
            // }

            if (!found) return false;
        }
        return true;
    };

    int l = 0, r = 1e9 + 20;
    while (r - l > 1) {
        int c = (l + r) / 2;

        if (can(c)) {
            r = c;
        } else {
            l = c;
        }
    }

    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}