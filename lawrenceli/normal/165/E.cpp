#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 1000100;
const int MAXK = 22;

int n, a[MAXN];
int dp[1<<MAXK];

int calc(int x) {
    if (dp[x] != -1) return dp[x];

    for (int i=0; i<MAXK; i++)
        if (x & 1<<i) {
            int res = calc(x ^ 1<<i);
            if (res) return dp[x] = res;
        }

    return dp[x] = 0;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        dp[a[i]] = a[i];
    }

    for (int i=0; i<(1<<MAXK); i++) calc(i);

    for (int i=0; i<n; i++) {
        int res = calc(a[i] ^ ((1<<MAXK) - 1));
        if (res == 0) cout << -1 << ' ';
        else cout << res << ' ';
    }

    return 0;
}