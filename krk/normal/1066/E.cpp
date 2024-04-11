#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int n, m;
string A, B;
int pw2[Maxn], sum[Maxn];
int res;

int main()
{
    cin >> n >> m;
    cin >> A >> B;
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    sum[0] = B[0] == '1';
    for (int i = 1; i < m; i++)
        sum[i] = sum[i - 1] + (B[i] == '1');
    for (int i = 0; i < n; i++) if (A[i] == '1') {
        int hm = (m - n) + i;
        if (hm >= 0) res = (res + ll(sum[hm]) * pw2[n - 1 - i]) % mod;
    }
    printf("%d\n", res);
    return 0;
}