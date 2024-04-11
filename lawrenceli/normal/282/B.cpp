#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;

int n, a[MAXN], g[MAXN], s;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d %d", &a[i], &g[i]);
    for (int i=0; i<n; i++) s += a[i];
    for (int m=0; m<=n; m++) {
        if (abs(s - 1000*(n - m)) <= 500) {
            for (int i=0; i<m; i++) printf("A");
            for (int i=0; i<n-m; i++) printf("G");
            return 0;
        }
    }
    printf("-1\n");
}