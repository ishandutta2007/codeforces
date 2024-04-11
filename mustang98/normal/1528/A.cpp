#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int l[max_n];
int r[max_n];
vector<int> v[max_n];
int n;
ll dp[max_n][2];

void clr() {
    for (int i = 0; i < n; ++i) {
        v[i].clear();
    }
}

void dfs(int cur, int pr) {
    dp[cur][0] = dp[cur][1] = 0;
    for (int to : v[cur]) {
        if (to == pr) continue;
        dfs(to, cur);
        dp[cur][0] += max(abs(l[cur] - l[to]) + dp[to][0], abs(l[cur] - r[to]) + dp[to][1]);
        dp[cur][1] += max(abs(r[cur] - l[to]) + dp[to][0], abs(r[cur] - r[to]) + dp[to][1]);
    }
}



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        clr();
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", l + i, r + i);
            //cin >> l[i] >> r[i];
        }
        for (int i = 0; i + 1 < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            //cin >> a >> b;
            --a, --b;
            v[a].PB(b);
            v[b].PB(a);
        }
        dfs(0, -1);
        printf("%lld\n",max(dp[0][0], dp[0][1]));
        //cout << max(dp[0][0], dp[0][1]) << "\n";
    }

    return 0;
}