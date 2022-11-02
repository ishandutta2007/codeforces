#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 100100;
const int MAXM = 21;

int n, m, d;
int num[MAXN], freq[MAXM];
int dp[1<<MAXM]; //bad

int calc(int x) {
    int& ret = dp[x];
    if (ret != -1) return ret;
    for (int i=0; i<m; i++)
        if (!(x & 1<<i))
            if (calc(x | 1<<i)) return ret = 1;
    return ret = 0;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> d;
    for (int i=0; i<m; i++) {
        int s; cin >> s;
        for (int j=0; j<s; j++) {
            int x; cin >> x;
            num[x] = i+1;
        }
    }

    dp[(1<<m)-1] = 0;

    for (int i=1; i<=d; i++) freq[num[i]]++;
    for (int i=1; i<=n-d+1; i++) {
        int x = 0;
        for (int j=1; j<=m; j++)
            if (!freq[j])
                x += 1<<(j-1);
        dp[x] = 1;
        freq[num[i]]--;
        freq[num[i+d]]++;
    }

    for (int i=0; i<=m; i++)
        for (int j=0; j<(1<<m); j++)
            if (__builtin_popcount(j) == i)
                if (!calc(j)) {
                    cout << i << '\n';
                    return 0;
                }
    return 0;
}