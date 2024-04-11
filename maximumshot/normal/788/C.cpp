#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const D = 1e3 + 5;

int n, k;
bool have[D];
vec< int > a;
int dist[2 * D];

int main() {

    scanf("%d %d", &n, &k);

    for(int x, i = 1;i <= k;i++) {
        scanf("%d", &x);
        have[x] = 1;
    }

    if(have[n]) {
        puts("1");
        return 0;
    }

    {
        int less = 0;
        int bigg = 0;
        for(int i = 0;i < D;i++) {
            if(!have[i]) continue;
            a.push_back(i - n);
            if(i < n) {
                less = 1;
            }else if(i > n) {
                bigg = 1;
            }
        }
        if(!less || !bigg) {
            puts("-1");
            return 0;
        }
    }

    queue< int > q;

    for(int i = 0;i < 2 * D;i++) {
        dist[i] = inf;
    }
    dist[0 + D] = 0;
    q.push(0 + D);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int x : a) {
            int to = v + x;
            if(to < 0 || to >= 2 * D) continue;
            if(dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    int res = inf;

    for(int x : a) {
        res = min(res, dist[-x + D] + 1);
    }

    printf("%d\n", res);

    return 0;
}