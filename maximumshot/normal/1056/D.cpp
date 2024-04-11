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

const int N = 1e5 + 5;

int n;
vec< int > g[N];
int dp[N];
int h[N];

void dfs(int v) {
    if(g[v].empty()) dp[v] = 1;
    for(int to : g[v]) {
        h[to] = h[v] + 1;
        dfs(to);
        dp[v] += dp[to];
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int p, i = 2;i <= n;i++) {
        scanf("%d", &p);
        g[p].push_back(i);
    }

    dfs(1);

    vec< pii > ar;

    for(int v = 1;v <= n;v++) {
        ar.push_back({dp[v], v});
//        cout << v << " : " << h[v] << "\n";
    }

    sort(ALL(ar));

    set< pii > q;

    for(int i = 1;i <= n;i++) {
        int v = ar[i - 1].second;
//        cout << v << " !\n";
//        continue;
        q.insert({dp[v], v});
        for(int to : g[v]) {
            q.erase({dp[to], to});
        }
        printf("%d ", (--q.end())->first);
    }

    printf("\n");

    return 0;
}