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
#define x my_x
#define rnk __builtin_popcount

using namespace std;

typedef long long int ll;

const long double pi = 3.141592653589793;
const long double eps = 1e-7;

const int MAXN = 2000000;
const int INF = 1e9 + 10;
const ll LONGINF = 4e18;
const int mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    if (n == 2) {
        cout << 1;
        return;
    }
    ll a = 1, b = 2, c = 1;
    while (b < n) {
        ll t = a + b + 1;
        a = b;
        b = t;
        ++c;
    }
    cout << c;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();

    return 0;
}