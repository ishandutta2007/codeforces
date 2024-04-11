#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10, mod = 998244353;

void plusle (int &a, int b) {
    ((a += b)) >= mod ? a -= mod : a;
}

void minun (int &a, int b) {
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

int power (int a, long long b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res ,a);
    return res;
}

int inv (int a) {
    return power(a, mod - 2);
}

vector<int> a[nax];
int dp[nax][3], n;

void dfs (int nod, int pa) {

    int ret = 1;

    int really = 1;

    int top = 1;

    int pref[(int)a[nod].size() + 2];
    pref[0] = 1;

    for (int to : a[nod]) {
        if (to == pa) continue;
        dfs(to, nod);

        ret = mul(ret, add(dp[to][0], dp[to][1]));
        really = mul(really ,add(dp[to][0], add(dp[to][1], dp[to][1])));
        pref[top ++] = really;

    }

    dp[nod][0] = ret;
    dp[nod][2] = sub(really, ret);

    really = 1;
    -- top;

    for (auto to = a[nod].rbegin() ; to != a[nod].rend() ; ++ to) {
        if (*to == pa) continue;

        plusle(dp[nod][1], 1LL * add(dp[*to][0], dp[*to][2]) * mul(pref[top - 1], really) % mod);
        really = mul(really, add(dp[*to][0], add(dp[*to][1], dp[*to][1])));

        -- top;
    }



}

int main () {

    scanf("%d", &n);

    for (int i = 1 ; i < n; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0);


    printf("%d\n", add(dp[1][0], dp[1][1]));
}

/**
Some notes for future reading

dp[v][0] is the number of way to split subtree v such that v is free vertex
dp[v][1] is the same, but v is used in matching
dp[v][2] is the same, but v is not free vertex and must match to something

for dp[v][0], it's trivially product of (dp[to][1] + dp[to][0])
Because you have to cut every edge and the number of valid ways for each subtree is (dp[to][1] + dp[to][0])

for dp[v][1] noticed that for each subtree, it the edge wasn't cut, we have dp[to][1] valid ways
else we have dp[to][0] + dp[to][1], then for each children, the number of valid ways is
dp[to][0] + 2 * dp[to][1]
We have to choose (only one!) free children in the matching, the number of ways is dp[to][0] + dp[to][1]
Compute prefix suffix product to make it O(n)

for dp[v][2] very similar to dp[v][1] each subtree has the number of valid cuts equal to dp[to][0] + 2 * dp[to][1]
But we must remember that this can't be free vertex, so we just need to minus dp[v][1] from the product
*/