#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <valarray>
#include <tuple>
#include <complex>
#include <bitset>
#include <assert.h>
#include <unordered_map>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;

const int INF = 2e9;
const int mod = 1e9 + 7;

using namespace std;

vector<int> prm[1000001];

int f[1000001][20];

void init() {
    for (int i = 2; i <= 1000000; ++i) {
        if (prm[i].size() == 0) {
            for (int j = 1; i * j <= 1000000; ++j) {
                int t = i * j;
                prm[t].pb(0);
                while (t%i == 0)
                    ++prm[i * j].back(), t /= i;
            }
        }
    }
    for (int i = 0; i <= 1000000; ++i)
        for (int j = 0; j < 20; ++j) {
            if (j == 0)
                f[i][j] = 1;
            else if (i == 0)
                f[i][j] = 2;
            else
                f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
        }
}

void solve() {
    init();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n, r;
        scanf("%d%d", &r, &n);
        ll ans = 1;
        for (auto k : prm[n])
            ans *= f[r][k], ans %= mod;
        printf("%I64d\n", ans);
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}