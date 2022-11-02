#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 300100;
const int MAXLG = 20;

int n, a[MAXN], tmin[MAXN][MAXLG], tgcd[MAXN][MAXLG];

int gcd(int x, int y) {
    if (x > y) swap(x, y);
    if (x == 0) return y;
    return gcd(y%x, x);
}

int gmin(int l, int r) {
     int d;
     for (d=0; 1<<d <= r-l; d++); d--;
     return min(tmin[l][d], tmin[r-(1<<d)][d]);
}

int ggcd(int l, int r) {
    int d;
    for (d=0; 1<<d <= r-l; d++); d--;
    return gcd(tgcd[l][d], tgcd[r-(1<<d)][d]);
}

bool pos(int mid) {
    for (int l=0; l+mid < n; l++) {
        int r = l + mid + 1;
        if (gmin(l, r) == ggcd(l, r)) return 1;
    }
    return 0;
}

int ans[MAXN], cnt;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        tmin[i][0] = tgcd[i][0] = a[i];
    }
    for (int d=1; (1<<(d-1)) < n; d++) {
        for (int i=0; i<n; i++) {
            tmin[i][d] = i+(1<<(d-1)) >= n ? tmin[i][d-1] : min(tmin[i][d-1], tmin[i+(1<<(d-1))][d-1]);
            tgcd[i][d] = i+(1<<(d-1)) >= n ? tgcd[i][d-1] : gcd(tgcd[i][d-1], tgcd[i+(1<<(d-1))][d-1]);
        }
    }
    int lo = 0, hi = MAXN;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (pos(mid)) lo = mid;
        else hi = mid - 1;
    }
    for (int l=0; l+lo < n; l++) {
        int r = l + lo + 1;
        if (gmin(l, r) == ggcd(l, r)) {
            ans[cnt++] = l + 1;
        }
    }
    printf("%d %d\n", cnt, lo);
    for (int i=0; i<cnt; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}