#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 55;
const int MAXL = 20;

int n, l;
ll d[1<<MAXL], num[MAXL+1];
char s[MAXN][MAXL+5];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> s[i];
    l = strlen(s[0]);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i != j) {
                int mask = 0;
                for (int k=0; k<l; k++)
                    if (s[i][k] == s[j][k])
                        mask += 1<<k;
                d[mask] |= 1LL<<i;
            }

    for (int i=(1<<l)-1; i>=0; i--)
        for (int j=0; j<l; j++)
            if (!(i&1<<j))
                d[i] |= d[i | 1<<j];

    for (int i=0; i<1<<l; i++) {
        int cnt = __builtin_popcount(i)+1;
        for (int j=0; j<l; j++)
            if (!(i&1<<j)) {
                int x = __builtin_popcountll(d[i] ^ d[i | 1<<j]);
                num[cnt] += x;
            }
    }

    double ans = 0;
    for (int i=1; i<=l; i++) {
        double x = num[i];
        for (int j=0; j<i-1; j++)
            x *= double(i-j-1) / (l-j);
        x /= l-i+1;
        ans += x*i;
    }
    ans /= n;

    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}