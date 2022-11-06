#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
int x[N], y[N];

int getDirection(int w) {
    int dx = x[(w + 1) % n] - x[w];
    int dy = y[(w + 1) % n] - y[w];
    if (dy > 0) {
        return 0;
    } else if (dx > 0) {
        return 1;
    } else if (dy < 0) {
        return 2;
    } else {
        return 3;
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int pos = 1;
    int dir = getDirection(n - 1);

    int turnsRight = 0;
    for (int i = 0; i < n; i++) {
        int dir2 = getDirection(i);
        if ((dir + 1) % 4 == dir2) {
            turnsRight++;
        }
        dir = dir2;
    }

    int turnsLeft = n - turnsRight;
    if (turnsRight > turnsLeft) {
        printf("%d\n", turnsLeft);
    } else {
        printf("%d\n", turnsRight);
    }

    return 0;
}