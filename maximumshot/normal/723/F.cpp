#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n, m;
vec< int > g[N];
int s, ds, t, dt;

int p[N];
int h[N];

int find(int x) { return (p[x] == x?x : p[x] = find(p[x])); }

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(h[x] == h[y]) {
        p[y] = x;
        h[x]++;
    }else {
        if(h[x] < h[y]) swap(x, y);
        p[y] = x;
    }
    return 1;
}

bool solve() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        p[i] = i;
        h[i] = 0;
    }

    vec< pii > edge(m);

    for(int u, v, i = 1;i <= m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        edge[i - 1] = {u, v};
    }

    scanf("%d %d %d %d", &s, &t, &ds, &dt);

    vec< pii > res;

    for(pii ed : edge) {
        int u, v;
        tie(u, v) = ed;
        if(u == s || u == t || v == s || v == t) continue;
        if(merge(u, v)) {
            res.push_back({u, v});
        }
    }

    vec< int > can_s(n + 1, -1);
    vec< int > can_t(n + 1, -1);

    for(int to : g[s]) can_s[find(to)] = to;
    for(int to : g[t]) can_t[find(to)] = to;

    set< int > all;
    for(int i = 1;i <= n;i++) {
        if(i == s || i == t) continue;
        all.insert(find(i));
    }

    for(auto it = all.begin();it != all.end();) {
        int x = *it;
        if(can_s[x] != -1) {
            if(can_t[x] != -1) {
                it++;
            }else {
                if(ds) {
                    ds--;
                    res.push_back({can_s[x], s});
                    it = all.erase(it);
                }else {
                    printf("No\n");
                    return true;
                }
            }
        }else {
            if(can_t[x] != -1) {
                if(dt) {
                    dt--;
                    res.push_back({can_t[x], t});
                    it = all.erase(it);
                }else {
                    printf("No\n");
                    return true;
                }
            }else {
                printf("No\n");
                return true;
            }
        }
    }

    for(int x : all) {
        if(!dt && !ds) {
            printf("No\n");
            return true;
        }
        if(ds > dt) {
            ds--;
            res.push_back({can_s[x], s});
        }else {
            dt--;
            res.push_back({can_t[x], t});
        }
    }

    for(auto ed : res) {
        merge(ed.first, ed.second);
    }

    for(int to : g[s]) {
        if(ds && (to != t || dt) && merge(s, to)) {
            ds--;
            if(to == t) dt--;
            res.push_back({s, to});
        }
    }
    for(int to : g[t]) {
        if(dt && (to != s || ds) && merge(t, to)) {
            dt--;
            if(to == s) ds--;
            res.push_back({t, to});
        }
    }

    int ok = 1;
    for(int i = 2;i <= n;i++) {
        if(find(i) != find(1)) {
            ok = 0;
            break;
        }
    }

    if(ok) {
        printf("Yes\n");
        for(auto ed : res) {
            printf("%d %d\n", ed.first, ed.second);
        }
    }else {
        printf("No\n");
    }

    //cout << "ds = " << ds << ", " << "dt = " << dt << "\n";

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}