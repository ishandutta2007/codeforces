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
    int n, k;
    cin >> n >> k;
    if (k > 3 
        || k == 1 
        || n < 4
        || k == 2 && n < 5
        || k == 3 && n < 4) {
        puts("-1");
        return;
    }
    if (k == 2) {
        printf("%d\n", n);
        for (int i = 0; i < n; ++i) {
            printf("%d %d\n", i + 1, (i + 1) % n + 1);
        }
        return;
    }
    printf("%d\n", 2 + n - 3 + (n - 3) * (n - 4) / 2);
    printf("1 2\n2 3\n");
    for (int i = 4; i <= n; ++i) {
        printf("3 %d\n", i);
    }
    for (int i = 4; i <= n; ++i)
        for (int j = 4; j < i; ++j)
            printf("%d %d\n", i, j);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}