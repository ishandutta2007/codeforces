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

ll T[1001000];

int f(int a) {
    return a & (a + 1);
}

ll ask(int p) {
    ll ans = 0;
    for (int i = p; i >= 0; i = (i&(i + 1)) - 1)
        ans += T[i];
    return ans;
}

void add(int p) {
    for (int i = p; i < 1001000; i |= i + 1)
        ++T[i];
}

ll sum(int l, int r) {
    if (l >= r)
        return 0;
    return ask(r - 1) - (l > 0 ? ask(l - 1) : 0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    k = min(k, n - k);
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        int cur = (ll)i * k % n;
        if ((ll)(i + 1) * k % n < cur) {
            ans += sum(cur + 1, n);
            ans += sum(0, (ll)(i + 1) * k % n);
        } else {
            ans += sum(cur + 1, (ll)(i + 1) * k % n);
        }
        ++ans;
        add(cur);
        add((ll)(i + 1) * k % n);
        printf("%lld ", ans);
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