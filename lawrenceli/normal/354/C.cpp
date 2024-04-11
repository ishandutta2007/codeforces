#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 300100;
const int MAXA = 2000100;

int n, k, a[MAXN], num[MAXA], pre[MAXA], ans, mina = 1e9;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        mina = min(mina, a[i]);
        num[a[i]] ++;
    }
    for (int i=0; i<MAXA-1; i++) pre[i+1] = pre[i] + num[i];
    for (int d=1; d<=mina; d++) {
        if (k >= d-1) {
            ans = d; continue;
        }
        int sum = 0;
        for (int i=0; i*d + k + 1 < MAXA; i++) {
            sum += pre[i*d+k+1] - pre[i*d];
        }
        if (sum >= n) ans = d;
    }
    printf("%d\n", ans);
    return 0;
}