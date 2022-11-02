#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b;

ll gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) return 0;
    return gcd(y, x%y) + x/y;
}

int main() {
    scanf("%I64d %I64d", &a, &b);
    printf("%I64d\n", gcd(a, b));
}