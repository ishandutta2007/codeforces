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

int main() {

    int n;

    scanf("%d", &n);

    vec< int > p(n + 1), b(n + 1);
    vec< vec< int > > g(n + 1);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i]);
        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }

    int tot = 1;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
        tot ^= b[i];
    }

    vec< char > used(n + 1);

    int cnt = 0;

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        queue< int > q;
        q.push(i);
        used[i] = 1;
        cnt++;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : g[v]) {
                if(!used[to]) {
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    if(cnt > 1) {
        tot += cnt;
    }

    printf("%d\n", tot);

    return 0;
}