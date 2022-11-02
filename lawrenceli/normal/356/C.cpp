#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, d, num[5], ans = 1e9;

int inter(int a, int b, int c, int d) {
    return max(min(b, d) - max(a, c), 0);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int a; scanf("%d", &a); num[a] ++;
        d += a;
    }
    for (int c=1; c<=n; c++) {
        int x = 4*c - d, y = d - 3*c;
        if (x < 0 || y < 0) continue;
        int m = 0, a = n - x - y, b = n - y;
        for (int i=0; i<=4; i++) {
            int lt = 0, rt = 0;
            for (int j=0; j<i; j++) lt += num[j];
            for (int j=0; j<=i; j++) rt += num[j];
            m += i * inter(lt, rt, 0, a);
            m += abs(i-3) * inter(lt, rt, a, b);
            m += abs(i-4) * inter(lt, rt, b, n);
        }
        ans = min(ans, m);
    }
    printf("%d\n", ans == 1e9 ? -1 : ans / 2);
    return 0;
}