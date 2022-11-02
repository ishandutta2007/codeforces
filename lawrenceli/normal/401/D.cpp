#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

const int MAXN = 18;
const int MAXM = 105;
const int MOD = 1e9;

string n;
int m, pow[MAXN];
ll dp[1<<MAXN][MAXM][2];
int freq[10];
ll fact[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    int l = n.length();
    for (int i=0; i<l; i++) freq[n[i]-'0'] ++;
    fact[0] = 1;
    for (int i=1; i<MAXN; i++) fact[i] = fact[i-1] * i;
    dp[0][0][0] = 1;
    pow[0] = 1;
    for (int i=1; i<MAXN; i++) pow[i] = (pow[i-1] * 10) % m;
    for (int i=0; i<l; i++) {
        int x = n[i] - '0';
        for (int j=0; j<(1<<l); j++)
            for (int k=0; k<m; k++)
                if (dp[j][k][0])
                    for (int i1=0; i1<l; i1++)
                        if (!(j & 1<<i1) && (x != 0 || i1 != l-1))
                            dp[j | 1<<i1][(k+x*pow[i1])%m][1] += dp[j][k][0];

        for (int j=0; j<(1<<l); j++)
            for (int k=0; k<m; k++)
                dp[j][k][0] = dp[j][k][1], dp[j][k][1] = 0;
    }

    ll ans = dp[(1<<l)-1][0][0];
    for (int i=0; i<10; i++) ans /= fact[freq[i]];
    cout << ans << '\n';

    return 0;
}