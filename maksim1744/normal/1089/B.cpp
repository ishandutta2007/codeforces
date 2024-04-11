/*
    author:  Maksim1744
    created: 06.05.2021 12:05:56
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

vector<pair<int, int>> edmonds(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> match(n, -1);
    vector<int> p(n);
    vector<bool> u(n);
    vector<bool> ulca(n);
    vector<int> q(n + 5, -1);
    vector<int> base(n);
    vector<bool> blossom(n);
    int ql = 0, qr = 0;

    auto lca = [&](int a, int b) {
        ulca.assign(n, false);
        while (true) {
            a = base[a];
            ulca[a] = true;
            if (match[a] == -1)
                break;
            a = p[match[a]];
        }
        while (true) {
            b = base[b];
            if (ulca[b]) return b;
            b = p[match[b]];
        }
        return -1;
    };

    auto mark_path = [&](int v, int b, int k) {
        while (base[v] != b) {
            blossom[base[v]] = true;
            blossom[base[match[v]]] = true;
            p[v] = k;
            k = match[v];
            v = p[match[v]];
        }
    };

    auto find_path = [&](int root) {
        p.assign(n, -1);
        u.assign(n, false);
        for (int i = 0; i < n; ++i)
            base[i] = i;
        ql = qr = 0;
        q[qr++] = root;
        u[root] = true;
        while (ql < qr) {
            int v = q[ql++];
            for (auto k : g[v]) {
                if (base[v] == base[k] || match[v] == k) {
                    continue;
                } else if (k == root || (match[k] != -1 && p[match[k]] != -1)) {
                    blossom.assign(n, false);
                    int b = lca(v, k);
                    mark_path(v, b, k);
                    mark_path(k, b, v);
                    for (int i = 0; i < n; ++i) {
                        if (blossom[base[i]]) {
                            base[i] = b;
                            if (!u[i]) {
                                u[i] = true;
                                q[qr++] = i;
                            }
                        }
                    }
                } else if (p[k] == -1) {
                    p[k] = v;
                    if (match[k] == -1)
                        return k;
                    k = match[k];
                    u[k] = true;
                    q[qr++] = k;
                }
            }
        }
        return -1;
    };

    for (int i = 0; i < n; ++i) {
        if (match[i] == -1) {
            int v = find_path(i);
            while (v != -1) {
                match[v] = p[v];
                int k = match[p[v]];
                match[p[v]] = v;
                v = k;
            }
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
        if (match[i] > i)
            ans.eb(i, match[i]);
    return ans;
}

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n * 2 + m);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        g[i * 2].pb(i * 2 + 1);
        g[i * 2 + 1].pb(i * 2);
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                g[i * 2].pb(n * 2 + j);
                g[i * 2 + 1].pb(n * 2 + j);
                g[n * 2 + j].pb(i * 2);
                g[n * 2 + j].pb(i * 2 + 1);
            }
        }
    }
    auto mat = edmonds(g);
    show(mat);
    map<int, int> cnt;
    for (auto [a, b] : mat) {
        if ((a ^ 1) == b) continue;
        cnt[min(a, b) / 2]++;
    }
    int ans = 0;
    for (auto [a, b] : cnt)
        ans += (b == 2);
    cout << ans << '\n';
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