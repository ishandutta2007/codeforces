#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, i, j, a, b;

int calc(int k, int l) {
    if (abs(i-k) % a || abs(j-l) % b) return 1e9;
    int x = abs(i-k) / a, y = abs(j-l) / b;
    if (x%2 != y%2) return 1e9;
    return max(x, y);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d %d %d %d", &n, &m, &i, &j, &a, &b);
    int ans = 1e9;
    ans = min(ans, calc(1, m));
    ans = min(ans, calc(n, 1));
    ans = min(ans, calc(n, m));
    ans = min(ans, calc(1, 1));
    if (ans != 0 && (i+a > n && i-a < 1 || j+b > m && j-b < 1)) ans = 1e9;
    if (ans == 1e9) printf("Poor Inna and pony!\n");
    else printf("%d\n", ans);
    return 0;
}