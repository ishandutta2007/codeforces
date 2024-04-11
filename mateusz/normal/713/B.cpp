#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, M = 1e6 + 7, P = 15426833;

int n;

struct Rect {
    int xp, yp, xk, yk;
};

int cnt;
int query(int xp, int yp, int xk, int yk) {
    cnt++;
    printf("? %d %d %d %d\n", xp, yp, xk, yk);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int divideHorizontal() {
    int low = 1;
    int high = n;
    int ret = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        int res = query(1, 1, n, mid);
        if (res >= 1) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ret + 1 > n || query(1, ret + 1, n, n) != 1) return -1;
    return ret;
}

int divideVertical() {
    int low = 1;
    int high = n;
    int ret = n;
    int res;
    while (low <= high) {
        int mid = (low + high) / 2;
        res = query(1, 1, mid, n);
        if (res >= 1) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ret + 1 > n || query(ret + 1, 1, n, n) != 1) return -1;
    return ret;
}

Rect solve(int lowX, int lowY, int highX, int highY) {
    Rect ret;
    int low = lowX;
    int high = highX;
    while (low <= high) {
        int midX = (low + high) / 2;
        if (query(lowX, lowY, midX, highY) >= 1) {
            ret.xk = midX;
            high = midX - 1;
        } else {
            low = midX + 1;
        }
    }
    low = lowX;
    high = highX;
    while (low <= high) {
        int midX = (low + high) / 2;
        if (query(midX, lowY, highX, highY) >= 1) {
            ret.xp = midX;
            low = midX + 1;
        } else {
            high = midX - 1;
        }
    }

    low = lowY;
    high = highY;
    while (low <= high) {
        int midY = (low + high) / 2;
        if (query(lowX, lowY, highX, midY) == 1) {
            ret.yk = midY;
            high = midY - 1;
        } else {
            low = midY + 1;
        }
    }
    low = lowY;
    high = highY;
    while (low <= high) {
        int midY = (low + high) / 2;
        if (query(lowX, midY, highX, highY) == 1) {
            ret.yp = midY;
            low = midY + 1;
        } else {
            high = midY - 1;
        }
    }
    return ret;
}
int main() {

    scanf("%d", &n);
    int div = divideVertical();
    if (div == -1) {
        div = divideHorizontal();
        Rect p1 = solve(1, 1, n, div);
        Rect p2 = solve(1, div + 1, n, n);
        assert(cnt < 200);
        printf("! %d %d %d %d %d %d %d %d\n", p1.xp, p1.yp, p1.xk, p1.yk, p2.xp, p2.yp, p2.xk, p2.yk);
        fflush(stdout);
    } else {
        Rect p1 = solve(1, 1, div, n);
        Rect p2 = solve(div + 1, 1, n, n);
        assert(cnt < 200);
        printf("! %d %d %d %d %d %d %d %d\n", p1.xp, p1.yp, p1.xk, p1.yk, p2.xp, p2.yp, p2.xk, p2.yk);
        fflush(stdout);
    }

    return 0;
}