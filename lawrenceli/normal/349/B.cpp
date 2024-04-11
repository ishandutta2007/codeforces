#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 1000010;

int v, a[100], num[MAXV], cnt, mina = 1e9, mini;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &v);
    for (int i=1; i<=9; i++) scanf("%d", &a[i]);
    for (int i=1; i<=9; i++) {
        if (mina >= a[i]) mina = a[i], mini = i;
    }
    if (v < mina) {
        printf("-1\n"); return 0;
    }
    while (v >= mina) num[cnt++] = mini, v -= mina;
    for (int i=0; i<cnt; i++) {
        for (int j=9; j>mini; j--) {
            if (v >= a[j] - mina) {
                v -= a[j] - mina, num[i] = j;
                break;
            }
        }
    }
    for (int i=0; i<cnt; i++) printf("%d", num[i]);
}