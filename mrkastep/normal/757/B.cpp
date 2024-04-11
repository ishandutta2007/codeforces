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

const int INF = 2e9;

using namespace std;

int d[100100];

void solve() {
    for (int i = 0; i < 100100; ++i)
        d[i] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; ++j)
            if (a%j == 0) {
                ++d[j];
                while (a%j == 0)
                    a /= j;
            }
        if (a > 1)
            ++d[a];
    }
    int ans = 1;
    for (int i = 2; i < 100100; ++i)
        ans = max(ans, d[i]);
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