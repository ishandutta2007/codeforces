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

void solve() {
    int n;
    cin >> n;
    int c[5] = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ++c[a];
    }
    int ans = c[4];
    ans += c[3];
    c[1] -= min(c[1], c[3]);
    ans += c[2] / 2;
    c[2] %= 2;
    if (c[2]) {
        ++ans;
        c[1] -= min(c[1], 2);
    }
    ans += (c[1] + 3) / 4;
    cout << ans;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}