#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n, a[MAXN], m, g = 2e9;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        m = max(m, a[i]);
        g = gcd(g, a[i]);
    }
    int x = m / g - n;
    if (x % 2 == 0) printf("Bob\n");
    else printf("Alice\n");
}