#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1000000009;

int n, m, k;

ll pow(int b, int e) {
    if (e==0) return 1;
    ll x = pow(b, e/2);
    if (e%2==0) return (x*x)%MOD;
    return ((x*x)%MOD*b)%MOD;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d", &n, &m, &k);
    int x = max(0, n/k + m - n);
    printf("%d\n", ((pow(2, x+1) - 2) * k % MOD + m - k*x + MOD)%MOD);
}