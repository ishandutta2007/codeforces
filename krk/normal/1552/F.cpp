#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int mod = 998244353;

int n;
int X[Maxn], Y[Maxn], S[Maxn];
int BIT[Maxn];
int totres;

void Add(int x, int val)
{
    for (int i = x; i <= n; i += i & -i)
        BIT[i] = (BIT[i] + val) % mod;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res = (res + BIT[i]) % mod;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &X[i], &Y[i], &S[i]);
        int cur = lower_bound(X + 1, X + i, Y[i]) - X;
        int res = (X[i] - Y[i]) % mod;
        if (cur < i) {
            res = (res + Get(i - 1)) % mod;
            res = (res - Get(cur - 1) + mod) % mod;
        }
        Add(i, res);
        if (S[i] == 1) totres = (totres + res) % mod;
    }
    totres = (totres + X[n] + 1) % mod;
    cout << totres << endl;
    return 0;
}