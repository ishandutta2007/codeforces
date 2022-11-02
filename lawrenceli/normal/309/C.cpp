#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000100;

int n, m, a[40], b[40], ans;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        for (int j=0; j<=30; j++) {
            if (x & (1<<j)) a[j] ++;
        }
    }
    for (int i=0; i<m; i++) {
        int x; scanf("%d", &x); b[x] ++;
    }
    for (int i=0; i<=30; i++) {
        for (int j=0; j<b[i]; j++) {
            bool good = 0;
            for (int k=i; k<=30; k++) {
                if (a[k]) {
                    a[k] --;
                    for (int l=i; l<k; l++) a[l] ++;
                    good = 1;
                    ans++;
                    break;
                }
            }
            if (!good) {
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}