#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <ios>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 15500;
const int MAXN2 = 505;

int n;
map<int, int> freq;
int C[MAXN][MAXN2];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        int k = 2;
        while (a > 1 && k*k <= a) {
            if (a % k == 0) freq[k]++, a /= k;
            else k++;
        }
        if (a > 1) freq[a]++;
    }

    C[0][0] = 1;
    for (int i=1; i<MAXN; i++) {
        C[i][0] = 1;
        for (int j=1; j<MAXN2; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }

    int ans = 1;
    for (typeof(freq.begin()) it = freq.begin(); it != freq.end(); it++)
        ans = (ll(ans) * C[it->second+n-1][n-1]) % MOD;

    cout << ans << '\n';
    return 0;
}