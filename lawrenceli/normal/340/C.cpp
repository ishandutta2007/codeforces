#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n, a[MAXN];
ll tot, d;

ll gcd(ll x, ll y) {
    if (x > y) swap(x, y);
    if (x == 0) return y;
    return gcd(y%x, x);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    tot = a[0]*n;
    for (int i=0; i<n-1; i++) {
        tot += ll(a[i+1] - a[i]) * (n-i-1) * (2*i + 3);
    }
    d = gcd(tot, n);
    printf("%I64d %I64d\n", tot / d, n / d);
}