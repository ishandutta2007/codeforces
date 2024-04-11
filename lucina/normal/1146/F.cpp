#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
constexpr int mod = 998244353;
int add (int a, int b) {
    return ((a += b) >= mod) ? a - mod : a;
}

int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int n;
vector <int> a[nax];
int dp[nax][3];
int f[3];
int g[3];

int main () {
    scanf("%d", &n);

    for (int i = 2 ; i <= n ; ++ i) {
        int x;
        scanf("%d", &x);
        a[x].push_back(i);
    }

    function <void (int)> dfs = [&] (int nod) -> void{
        for (int i : a[nod]) dfs(i);

        if (a[nod].empty()) {
            dp[nod][2] = 1;
            return ;
        }

        f[0] = 1;
        f[1] = f[2] = 0;

        for (int i : a[nod]) {
            /// didn't belong to any partition
            g[0] = mul(f[0], add(dp[i][0], dp[i][2]));
            /// connected to one children, need to be connected above

            g[1] = mul(f[1], add(dp[i][0], dp[i][2]));
            g[1] = add(g[1], mul(f[0], add(dp[i][1], dp[i][2])));
            /// connected to at least two children
            g[2] = mul(add(f[1], f[2]), add(dp[i][1], dp[i][2]));
            g[2] = add(g[2], mul(f[2], add(dp[i][0], dp[i][2])));
            for (int j = 0 ; j < 3 ; ++ j) f[j] = g[j];
        }

        for (int i = 0 ; i < 3 ; ++ i) dp[nod][i] = f[i];
    };

    dfs(1);
    printf("%d\n", add(dp[1][0], dp[1][2]));
}