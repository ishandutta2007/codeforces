#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    vec< int > c(n + 1);

    for(int i = 1;i <= n;i++) scanf("%d", &c[i]);

    vec< vec< int > > g(n + 1);

    for(int l, r, i = 0;i < m;i++) {
        scanf("%d %d", &l, &r);
        g[l].push_back(r);
        g[r].push_back(l);
    }

    vec< char > used(n + 1);
    vec< int > cnt(k + 1);
    queue< int > q;

    vec< int > buffer(n + 1);
    int buf_sz;

    int res = 0;

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        used[i] = 1;
        cnt[c[i]]++;
        q.push(i);
        buf_sz = 0;
        buffer[buf_sz++] = c[i];
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : g[v]) {
                if(!used[to]) {
                    used[to] = 1;
                    cnt[c[to]]++;
                    q.push(to);
                    buffer[buf_sz++] = c[to];
                }
            }
        }
        int mx = 0;
        for(int iter = 0;iter < buf_sz;iter++) {
            mx = max(mx, cnt[buffer[iter]]);
            cnt[buffer[iter]] = 0;
        }
        res += buf_sz - mx;
    }

    printf("%d\n", res);

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