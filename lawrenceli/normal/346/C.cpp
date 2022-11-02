#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100100;

int n, x[MAXN], a, b, ans;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &x[i]);
    sort(x, x + n); n = unique(x, x + n) - x;
    scanf("%d %d", &a, &b);
    while (a > b) {
        int stp = 1;
        for (int i=0; i<n; i++) {
            if (a-(a%x[i]) >= b) stp = max(stp, a%x[i]);
        }
        while (n > 0 && a-(a%x[n-1]) < b) n--;
        a -= stp; ans++;
    }
    printf("%d\n", ans);
    return 0;
}