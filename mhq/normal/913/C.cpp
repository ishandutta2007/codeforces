#include <bits/stdc++.h>
using namespace std;
long long L;
int n;
long long c[35];
long long ans[35];
long long solve(long long L, int i) {
    if (i == 0) return L * ans[0];
    if ((1 << i) > L) {
        return min(solve(L, i - 1), ans[i]);
    }
    else {
        return ans[i] + solve(L - (1 << i), i - 1);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> L;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < 31; i++) {
        long long a = (long long)1e18 + 10;
        for (int j = 0; j < n; j++) {
            if (j >= i) a = min(a, c[j]);
        }
        if (i > 0) a = min(a, 2 * ans[i - 1]);
        ans[i] = a;
        //for (int i = 0; i < n; i++)
    }
    cout << solve(L, 30);
    return 0;
}