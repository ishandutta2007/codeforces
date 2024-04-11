#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10, mod = 998244353;

void minun (int &a , int b) {
    ((a -= b) < 0) ? a += mod : a;
}

int add (int a, int b) {
    return ((a += b) >= mod) ? a - mod : a;
}

int sub (int a, int b) {
    return ((a -= b) < 0) ? a + mod : a;
}

int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int n;
vector<int> a[nax];
int dp[nax][3];

void dfs (int nod, int pa) {

    dp[nod][0] = dp[nod][1] = dp[nod][2] = 1;

    for (int v : a[nod]) {
        if (v == pa) continue;
        dfs(v, nod);

        int x = sub(add(dp[v][0], dp[v][1]) , dp[v][2]);

        dp[nod][0] = mul(dp[nod][0], add(x, add(dp[v][0], dp[v][1])));
        dp[nod][1] = mul(dp[nod][1], add(x, dp[v][0]));
        dp[nod][2] = mul(dp[nod][2] , x);
    }
}


int main () {

    scanf("%d", &n);

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0);

    int ans = add(dp[1][0], dp[1][1]);
    minun(ans, add(dp[1][2], 1));

    printf("%d\n", ans);
}

/**
Some notes:
Wow, this problem is indeed similar to Vasya and maximum matching though this one is easier

    dp[v][0] v is not chosen
    dp[v][1] v is chosen
    dp[v][2] v is free vertex, in essence isolated

    -> for each edge, two choices, remove or not
    dp[p][0] -> if (remove ? dp[v][0] + dp[v][1]) ? no, if we remove it can't be free vertex , so real answer is (dp[v][0] + dp[v][1] - dp[v][2])
                if (not remove? dp[v][0] + dp[v][1])

    dp[p][1] -> if (remove ? dp[v][0] + dp[v][1] - dp[v][2])
                  if (not remove? dp[v][0])

    dp[p][2] every thing is cut down, hence (dp[v][0] + dp[v][1] - dp[v][2])

*/
/*
    Good Luck
        -Lucina
*/