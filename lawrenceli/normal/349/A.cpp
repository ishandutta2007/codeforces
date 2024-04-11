#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int n, a[MAXN], x[3];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 25) x[0] ++;
        else if (a[i] == 50) {
            if (x[0] == 0) {
                printf("NO\n"); return 0;
            } else {x[0] --; x[1] ++;}
        } else {
            if (x[1] > 0) {
                if (x[0] == 0) {
                    printf("NO\n"); return 0;
                } else {x[0] --; x[1] --;}
            } else {
                if (x[0] < 3) {
                    printf("NO\n"); return 0;
                } else {x[0] -= 3;}
            }
        }
    }
    printf("YES\n");
}