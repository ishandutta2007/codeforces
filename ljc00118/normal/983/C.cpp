#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int from[N], to[N];
int n;
unordered_map <int, int> dp[N][10];

int solve(int i, int f, int mask) {
    if (i == n and !mask) return 0;
    if (dp[i][f].count(mask)) return dp[i][f][mask];
    int ans = INT_MAX;
    for (int g = 1; g <= 9; g++) {
        int j = i, temp = mask, pw = 1;
        for (int p = 0; p < 4; p++) {
            int cur = (temp / pw) % 10;
            if (cur == g) {
                temp -= cur * pw;
            }
            pw *= 10;
        }
        pw = 1;
        for (int p = 0; p < 4; p++) {
            int cur = (temp / pw) % 10;
            if (!cur && from[j] == g) {
                temp += to[j] * pw;
                ++j;
            }
            pw *= 10;
        }
        if (i != j || mask != temp) {
            ans = min(ans, solve(j, g, temp) + abs(f - g));
        }
    }
    return dp[i][f][mask] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &from[i], &to[i]);
    printf("%d\n", solve(0, 1, 0) + 2 * n);
    return 0;
}