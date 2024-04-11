#include <bits/stdc++.h>
using namespace std;
inline int query(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}
int dis11;
inline int calcly() {
    int L = 1, R = 1e9, ans = 1;
    while (L <= R) {
        int mid = L + R >> 1;
        if (query(1, mid) != dis11 - (mid - 1)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    return ans - 1;
}
int main() {
    dis11 = query(1, 1);
    int ly = calcly();
    int lx = dis11 + 2 - ly;
    int rx = query(1e9, 1) - ly + 1;
    int ry = query(1, 1e9) - lx + 1;
    rx = 1e9 - rx;
    ry = 1e9 - ry;
    printf("! %d %d %d %d\n", lx, ly, rx, ry);
}