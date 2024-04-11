#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Inf = 1000000000;

int T;
int n, d;
int dist[Maxn], a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &d);
        queue <int> Q;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == 0) {
                dist[i] = 0;
                Q.push(i);
            } else dist[i] = Inf;
        }
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            int u = (v + d) % n;
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, dist[i]);
        printf("%d\n", res >= Inf? -1: res);
    }
    return 0;
}