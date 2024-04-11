#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n;
int a[N];
ll sm[N];
vec< int > g[N];
pair< ll, ll > mx[N];
ll dp[N];
ll total = -inf64;

void dfs(int v, int par = -1) {
    sm[v] = a[v];
    mx[v] = make_pair(-inf64, -inf64);
    dp[v] = -inf64;
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
        sm[v] += sm[to];
        dp[v] = max(dp[v], dp[to]);
        if(dp[to] > mx[v].first) {
            mx[v].second = mx[v].first;
            mx[v].first = dp[to];
        }else if(dp[to] > mx[v].second) {
            mx[v].second = dp[to];
        }
    }
    dp[v] = max(dp[v], sm[v]);
    if(mx[v].first != -inf64 && mx[v].second != -inf64) {
        total = max(total, mx[v].first + mx[v].second);
    }
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ok = (int)g[1].size() > 1;

    for(int i = 2;i <= n;i++) {
        if((int)g[i].size() > 2) {
            ok = 1;
            break;
        }
    }

    if(!ok) {
        puts("Impossible");
        return 0;
    }

    dfs(1);

    cout << total << "\n";

    return 0;
}