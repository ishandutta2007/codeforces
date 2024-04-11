#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int maxn = 505;

int n, c[maxn];
bool pal[maxn][maxn];
int dp[maxn][maxn];
int pe[maxn], po[maxn];

int calc(int l, int r) {
    if (l == r) return 0;
    int& ret = dp[l][r];
    if (ret != -1) return ret;
    if (pal[l][r]) return ret = 1;
    ret = 1e9;

    if (c[l] == c[r - 1]) ret = min(ret, calc(l + 1, r - 1));

    for (int i = l; i < r - 1; i++) {
        if (pe[i] == 0) continue;
        int k = min(pe[i], min(i + 1 - l, r - i - 1));
        ret = min(ret, calc(l, i - k + 1) + calc(i + k + 1, r) + 1);
    }

    for (int i = l; i < r; i++) {
        int k = min(po[i], min(i + 1 - l, r - i));
        ret = min(ret, calc(l, i - k + 1) + calc(i + k, r) + 1);
    }

    for (int i = l + 1; i < r; i++)
        ret = min(ret, calc(l, i) + calc(i, r));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            pal[i][j] = 1;
            for (int k = i, l = j - 1; k < j; k++, l--)
                if (c[k] != c[l])
                    pal[i][j] = 0;
        }
    
    for (int i = 0; i < n - 1; i++) {
        int a = i, b = i + 1;
        while (a >= 0 && b < n && c[a] == c[b]) a--, b++;
        pe[i] = i - a;
    }

    for (int i = 0; i < n; i++) {
        int a = i, b = i;
        while (a >= 0 && b < n && c[a] == c[b]) a--, b++;
        po[i] = i - a;
    }

    memset(dp, -1, sizeof(dp));
    cout << calc(0, n) << '\n';
}