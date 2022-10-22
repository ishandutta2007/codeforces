#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int N = 1005;

int n, m;
int p[2 * N];
int g[2 * N];
int f[2 * N];
int used[2 * N];

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= 2 * n;i++) {
        scanf("%d", &p[i]);
        f[i] = p[i];
    }

    vec< pair< int, pii > > q;

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u] = v;
        g[v] = u;
        if(p[u] < p[v]) swap(u, v);
        q.push_back({p[u], {u, v} });
    }

    int t;

    scanf("%d", &t);

    if(t == 1) {

        sort(ALL(q));
        reverse(ALL(q));

        for(pair< int, pii > it : q) {
            printf("%d\n", it.second.first);
            fflush(stdout);
            int r;
            scanf("%d", &r);
            used[it.second.first] = used[it.second.second] = 1;
        }

        vec< pii > hlp;

        for(int i = 1;i <= 2 * n;i++) {
            if(used[i]) continue;
            hlp.push_back({p[i], i});
        }

        sort(ALL(hlp));
        reverse(ALL(hlp));

        for(pii p : hlp) {
            if(used[p.second]) continue;
            printf("%d\n", p.second);
            fflush(stdout);
            int r;
            scanf("%d", &r);
            used[r] = 1;
            used[p.second] = 1;
        }

        return 0;
    }else {

        int cnt = n;
        for(int it = 1;it <= n;it++) {
            int r;
            scanf("%d", &r);
            cnt--;
            used[r] = 1;

            if(g[r]) {
                printf("%d\n", g[r]);
                fflush(stdout);
                used[g[r]] = 1;
                continue;
            }

            break;
        }

        sort(ALL(q));
        reverse(ALL(q));

        for(pair< int, pii > it : q) {
            if(used[it.second.first]) continue;

            printf("%d\n", it.second.first);
            fflush(stdout);
            int r;
            if(cnt--)
                scanf("%d", &r);
            used[it.second.first] = used[it.second.second] = 1;
        }

        vec< pii > hlp;

        for(int i = 1;i <= 2 * n;i++) {
            if(used[i]) continue;
            hlp.push_back({p[i], i});
        }

        sort(ALL(hlp));
        reverse(ALL(hlp));

        for(pii p : hlp) {
            if(used[p.second]) continue;
            printf("%d\n", p.second);
            fflush(stdout);
            int r = 0;
            if(cnt--)
               scanf("%d", &r);
            used[r] = 1;
            used[p.second] = 1;
        }

    }

    return 0;
}