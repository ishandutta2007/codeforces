#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxm = 1000006;
const int mod = 1000000007;

int n;
int a[Maxm];
ll sum;
vector <int> neigh[Maxm];
int hit[Maxm];
int dp[Maxm];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll Traverse(int v)
{
    ll my = a[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        my += Traverse(u);
    }
    ll tk = sum / gcd(my, sum);
    if (tk <= n) hit[tk]++;
    return my;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Traverse(1);
    for (int i = n; i >= 1; i--) if (hit[i])
        for (int j = i + i; j <= n; j += i)
            hit[j] += hit[i];
    for (int i = n; i >= 1; i--) if (hit[i] == i) {
        dp[i] = 1;
        for (int j = i + i; j <= n; j += i)
            dp[i] = (dp[i] + dp[j]) % mod;
    }
    printf("%d\n", dp[1]);
    return 0;
}