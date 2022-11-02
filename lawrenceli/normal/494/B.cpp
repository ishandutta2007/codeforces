#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int n, m;
char s[MAXN], t[MAXN], w[2*MAXN];
int z[2*MAXN];
bool match[MAXN];

void init() {
    for (int i=0; i<m; i++) w[i] = t[i];
    for (int i=0; i<n; i++) w[i+m] = s[i];

    int l = 0, r = 0;
    for (int i=1; i<n+m; i++) {
        if (i>r) {
            l=r=i;
            while (r<n+m && w[r-l]==w[r]) r++;
            z[i]=r-l; r--;
        } else {
            int k=i-l;
            if (z[k]<r-i+1) z[i]=z[k];
            else {
                l=i;
                while (r<n+m && w[r-l]==w[r]) r++;
                z[i]=r-l; r--;
            }
        }
    }


    for (int i=m; i<n+m; i++)
        if (z[i] >= m)
            match[i-m] = 1;
}

const int MOD = 1e9 + 7;

int dp[MAXN], pre[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s >> t;
    n = strlen(s), m = strlen(t);
    init();

    dp[0] = 1;
    pre[1] = 1;
    int last = -1;
    for (int i=1; i<=n; i++) {
        dp[i] = dp[i-1];
        if (i>=m && match[i-m]) last = i-m+1;
        if (last != -1) dp[i] = (dp[i]+pre[last])%MOD;
        pre[i+1] = (pre[i]+dp[i])%MOD;
    }

    cout << (dp[n]+MOD-1)%MOD << '\n';
    return 0;
}