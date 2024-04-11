#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n, k, m;
vec< pii > g[85];
int dp[85][85][85][85];
bool used[85][85][85][85];

int rec(int l, int r, int last, int cnt) {
    if(l < 1 || l > n || r < 1 || r > n || l > r || last < l || last > r || cnt >= k) {
        return inf;
    }
    if(used[l][r][last][cnt]) {
        return dp[l][r][last][cnt];
    }
    used[l][r][last][cnt] = 1;
    if(cnt == 0) {
        return dp[l][r][last][cnt] = 0;
    }
    int res = inf;
    for(pii iter : g[last]) {
        int to = iter.first;
        int we = iter.second;
        if(to < l || to > r || to == last) continue;
        if(to < last) {
            res = min(res, rec(l, last - 1, to, cnt - 1) + we);
        }else {
            res = min(res, rec(last + 1, r, to, cnt - 1) + we);
        }
    }
    return dp[l][r][last][cnt] = res;
}

int main() {

    scanf("%d %d", &n, &k);
    scanf("%d", &m);

    for(int u, v, c, i = 0;i < m;i++) {
        scanf("%d %d %d", &u, &v, &c);
        g[u].push_back(make_pair(v, c));
    }

    for(int l = 0;l < 85;l++) {
        for(int r = 0;r < 85;r++) {
            for(int last = 0;last < 85;last++) {
                for(int cnt = 0;cnt < 85;cnt++) {
                    dp[l][r][last][cnt] = inf;
                }
            }
        }
    }

    int res = inf;

    for(int i = 1;i <= n;i++) {
        res = min(res, rec(1, n, i, k - 1));
    }

    printf("%d\n", res == inf ? -1 : res);

    return 0;
}