#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "fast-math")//, "rename-registers")//,"inline") //Optimization flags


#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5001, inf = 1000111222;

int dp1[max_n][max_n];
int dp2[max_n][max_n];
int m[max_n];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        dp1[i][i] = m[i];
        dp2[i][i] = m[i];
    }
    for (int l = 2; l <= n; ++l) {
        for (int s = 0; s <= n - l; ++s) {
            int i = s;
            int j = s + l - 1;
            dp1[i][j] = dp1[i][j - 1] ^ dp1[i + 1][j];
        }
    }
    for (int l = 2; l <= n; ++l) {
        for (int s = 0; s <= n - l; ++s) {
            int i = s;
            int j = s + l - 1;
            dp2[i][j] = max(dp2[i][j - 1], max(dp2[i + 1][j], dp1[i][j]));
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << dp2[l][r] << "\n";
    }
    return 0;
}