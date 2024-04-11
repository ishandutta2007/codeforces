/*
    author:  Maksim1744
    created: 28.01.2021 18:54:01
*/

#include "bits/stdc++.h"

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

void test_case(int test) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> e(m);
    cin >> e;
    vector<int> p(n), q(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < m; ++i) {
        e[i].first--;
        e[i].second--;
        deg[e[i].first]++;
        deg[e[i].second]++;
    }
    vector<int> good;
    int last = 1;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == n - 1) {
            p[i] = q[i] = last;
            ++last;
        } else {
            good.pb(i);
        }
    }
    vector<vector<int>> g(n);
    for (auto [a, b] : e) {
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    vector<int> to(n, -1);
    for (auto k : good) {
        int want = 0;
        for (int i = 0; i < g[k].size(); ++i) {
            if (want == k) ++want;
            if (want != g[k][i]) break;
            ++want;
        }
        if (want == k) ++want;
        to[k] = want;
        assert(want < n);
    }
    vector<bool> is_cycle(n, false);
    vector<vector<int>> cycles;
    vector<int> u(n, -1);
    int ustep = 0;
    vector<set<int>> from(n);
    vector<int> dist(n);
    for (auto k : good) {
        from[to[k]].insert(k);
    }
    show(good);
    show(from);
    show(to);
    for (auto k : good) {
        if (u[k] != -1) continue;
        ++ustep;
        while (u[k] == -1) {
            u[k] = ustep;
            k = to[k];
        }
        assert(u[k] == ustep);
        int v = k;
        show(k);
        vector<int> cycle = {v};
        is_cycle[v] = true;
        k = to[k];
        while (k != v) {
            is_cycle[k] = true;
            cycle.pb(k);
            k = to[k];
        }
        cycles.pb(cycle);
        show(cycle);
        assert(cycle.size() >= 2);
        ++ustep;
        queue<int> q;
        for (auto v : cycle) {
            q.push(v);
            dist[v] = 0;
        }
        for (auto k : cycle) {
            for (auto v : from[k]) {
                if (is_cycle[v]) {
                    from[k].erase(v);
                    break;
                }
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            u[v] = ustep;
            for (auto k : from[v]) {
                if (!is_cycle[k]) {
                    q.push(k);
                    dist[k] = dist[v] + 1;
                }
            }
        }
    }

    vector<pair<int, int>> cand;
    for (auto k : good) {
        if (!is_cycle[k])
            cand.eb(dist[k], k);
    }
    sort(cand.begin(), cand.end());
    reverse(cand.begin(), cand.end());
    show(cand);
    vector<bool> dead(n, false);

    auto connect_with_par = [&](const vector<int> &ch, int par) {
        assert(!ch.empty());
        for (auto k : ch) {
            q[k] = last;
            p[k] = last + 1;
            ++last;
        }
        q[par] = q[ch.back()] + 1;
        p[par] = p[ch[0]] - 1;
        ++last;
    };

    function<void(vector<int>&)> connect_line = [&](vector<int> &v) {
        assert(v.size() >= 2);
        while (!v.empty()) {
            if (v.size() == 3) {
                p[v[0]] = last + 1;
                p[v[1]] = last + 2;
                p[v[2]] = last;

                q[v[0]] = last + 2;
                q[v[1]] = last;
                q[v[2]] = last + 1;
                last += 3;
                break;
            } else {
                int a = v.back();
                v.pop_back();
                int b = v.back();
                v.pop_back();
                p[a] = q[b] = last;
                ++last;
                p[b] = q[a] = last;
                ++last;
            }
        }
    };

    show(cand);

    for (int i = 0; i < cand.size() && cand[i].first >= 2; ++i) {
        int v = cand[i].second;
        if (dead[v]) continue;
        int par = to[v];
        vector<int> ch(from[par].begin(), from[par].end());
        for (auto u : ch) {
            dead[u] = true;
        }
        dead[par] = true;
        show(ch, par);
        connect_with_par(ch, par);
        from[to[par]].erase(par);
    }

    show(p);
    show(q);
    show(from);
    show(cycles);

    for (auto cycle : cycles) {
        vector<int> bad;
        for (int i = 0; i < cycle.size(); ++i) {
            if (!from[cycle[i]].empty()) bad.pb(i);
        }
        show(bad);
        if (bad.empty()) {
            connect_line(cycle);
            continue;
        }
        for (int i = 0; i < bad.size(); ++i) {
            int u = bad[i];
            int v = bad[(i + 1) % bad.size()];
            int ln = v - u - 1;
            if (ln < 0) ln += (int)cycle.size();
            if (ln == 0) continue;
            show(u, v, ln);
            if (ln == 1) {
                vector<int> ch(from[cycle[u]].begin(), from[cycle[u]].end());
                ch.pb(cycle[(u + 1) % cycle.size()]);
                show(ch, cycle[u]);
                show(p, q, last);
                connect_with_par(ch, cycle[u]);
                show(p, q, last);
                dead[cycle[u]] = true;
            } else {
                vector<int> cur;
                for (int j = u + 1; j != v; j = (j + 1) % cycle.size())
                    cur.pb(cycle[j]);
                connect_line(cur);
            }
        }
        for (auto k : cycle) {
            if (!from[k].empty() && !dead[k]) {
                connect_with_par(vector<int>(from[k].begin(), from[k].end()), k);
            }
        }
    }
    cout << p << '\n';
    cout << q << '\n';
    // show(p, q);
    // for (auto k : good) {
    //     assert(p[k] != q[k]);
    // }
    // sort(p.begin(), p.end());
    // p.erase(unique(p.begin(), p.end()), p.end());
    // sort(q.begin(), q.end());
    // q.erase(unique(q.begin(), q.end()), q.end());
    // assert(p == q && p.size() == n && p[0] == 1 && p.back() == n);
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