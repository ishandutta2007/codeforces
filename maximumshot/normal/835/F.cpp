#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n;
vec< pii > g[N];
vec< pii > cycle;
pii from[N];

int st, fn;

int color[N];

bool dfs(int v, int par = -1) {
    color[v] = 1;
    for(pii iter : g[v]) {
        int to, w;
        tie(to, w) = iter;
        if(to == par) continue;
        if(!color[to]) {
            from[to] = make_pair(v, w);
            if(dfs(to, v)) return true;
        }else if(color[to] == 1) {
            st = to;
            fn = v;
            from[st] = make_pair(fn, w);
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void findCycle() {
    dfs(1);
    for(int u = fn;;) {
        int v = from[u].first;
        int w = from[u].second;
        cycle.push_back(make_pair(u, w));
        if(v == fn) break;
        else u = v;
    }
}

ll pref[N];
bool in_cycle[N];
ll mx[N];
ll best[N];

void go(int v, int par = -1) {
    mx[v] = 0;
    best[v] = 0;
    ll cur = -inf64;
    for(pii iter : g[v]) {
        int to, w;
        tie(to, w) = iter;
        if(to == par || in_cycle[to]) continue;
        go(to, v);
        mx[v] = max(mx[v], mx[to] + w);
        best[v] = max(best[v], best[to]);
        if(cur != -inf64) {
            best[v] = max(best[v], cur + mx[to] + w);
        }
        cur = max(cur, mx[to] + w);
    }
    best[v] = max(best[v], mx[v]);
}

void query() {
    for(int i = 0;i < (int)cycle.size();i++) {
        in_cycle[cycle[i].first] = 1;
    }
    for(int i = 0;i < (int)cycle.size();i++) {
        go(cycle[i].first);
    }
    set< pair< ll, int > > M1, M2;
    for(int i = 0;i < (int)cycle.size() - 1;i++) {
        int u = cycle[i].first;
        int w = cycle[i].second;
        int v = cycle[i + 1].first;
        pref[v] = pref[u] + w;
    }
    for(int i = 0;i < (int)cycle.size();i++) {
        int v = cycle[i].first;
        M1.insert(make_pair(mx[v] - pref[v], v));
        M2.insert(make_pair(mx[v] + pref[v], v));
    }
    ll res = inf64;
    ll max_best = -inf64;
    for(int i = 0;i < (int)cycle.size();i++) {
        max_best = max(max_best, best[cycle[i].first]);
    }
    ll Sum = 0;
    for(int i = 0;i < (int)cycle.size();i++) {
        Sum += cycle[i].second;
    }

//    for(int i = 0;i < (int)cycle.size();i++) {
//        cout << cycle[i].first << " " << cycle[i].second << " ";
//        int v = cycle[i].first;
//        cout << pref[v] << " " << mx[v] << " " << best[v] << "\n";
//    }

//    cout << "Sum = " << Sum << "\n";

    for(int j, i = 0;i < (int)cycle.size();i++) {
        j = i - 1;
        if(j < 0) j += (int)cycle.size();
        int v = cycle[i].first;
        set< int > Q;
        {
            int cn = 0;
            for(auto it = --M1.end();cn < 2;it--, cn++) {
                Q.insert(it->second);
            }
            cn = 0;
            for(auto it = --M2.end();cn < 2;it--, cn++) {
                Q.insert(it->second);
            }
        }

//        cout << i << " : ";
//        for(int z = 1;z <= n;z++) cout << pref[z] << " ";
//        cout << "\n";

        ll cur_mx = -inf64;
        for(int v1 : Q) {
            for(int v2 : Q) {
                if(v1 == v2) continue;
//                cout << v1 << " " << v2 << " = ";
                ll tmp = mx[v1] + mx[v2] + pref[v2] - pref[v1];
                tmp = max(tmp, max_best);
//                cout << tmp << "\n";
                cur_mx = max(cur_mx, tmp);
            }
        }

        res = min(res, cur_mx);

        M1.erase(make_pair(mx[v] - pref[v], v));
        M2.erase(make_pair(mx[v] + pref[v], v));
        pref[v] = pref[cycle[(i + 1) % (int)cycle.size()].first] + Sum - cycle[i].second;
        M1.insert(make_pair(mx[v] - pref[v], v));
        M2.insert(make_pair(mx[v] + pref[v], v));
    }
    cout << res << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int u, v, w, i = 1;i <= n;i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    findCycle();
    query();

    return 0;
}