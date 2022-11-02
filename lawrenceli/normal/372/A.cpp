#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500100;

int n, s[MAXN];

bool good(int m) {
    if (m > n / 2) return 0;
    for (int i=0; i<m; i++) {
        if (s[i] * 2 > s[n-m+i]) return 0;
    }
    return 1;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &s[i]);
    sort(s, s + n);
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (good(mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%d\n", n - lo);
    return 0;
}