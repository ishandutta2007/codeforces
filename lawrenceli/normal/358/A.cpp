#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n, x[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &x[i]);
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            int x1 = x[i], x2 = x[i+1], x3 = x[j], x4 = x[j+1];
            if (x1 > x2) swap(x1, x2);
            if (x3 > x4) swap(x3, x4);
            if (x1 < x3 && x3 < x2 && x2 < x4) {
                printf("yes\n");
                return 0;
            }
        }
    }
    printf("no\n");
    return 0;
}