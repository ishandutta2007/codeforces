#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k;
long long xx, yy, xxx, yyy;
long long x[N], y[N];
int horizontal[N], vertical[N];
bool thrown[N];
long long area;

void solve(int w, int begHor, int endHor, int begVer, int endVer) {
    while (begHor <= endHor && thrown[horizontal[begHor]]) begHor++;
    while (begHor <= endHor && thrown[horizontal[endHor]]) endHor--;
    while (begVer <= endVer && thrown[vertical[begVer]]) begVer++;
    while (begVer <= endVer && thrown[vertical[endVer]]) endVer--;
    if (begHor > endHor || begVer > endVer) {
        area = 4;
        return;
    }
    if (x[horizontal[begHor]] == x[horizontal[endHor]] && y[vertical[begVer]] == y[vertical[endVer]]) {
        area = min(area, 4LL);
    } else if (x[horizontal[begHor]] == x[horizontal[endHor]]) {
        area = min(area, 2LL * (y[vertical[endVer]] - y[vertical[begVer]]));
    } else if (y[vertical[begVer]] == y[vertical[endVer]]) {
        area = min(area, 2LL * (x[horizontal[endHor]] - x[horizontal[begHor]]));
    } else {
        area = min(area, (x[horizontal[endHor]] - x[horizontal[begHor]]) * (y[vertical[endVer]] - y[vertical[begVer]]));
    }
    if (w > k) {
        return;
    }

    thrown[horizontal[begHor]] = true;
    solve(w + 1, begHor, endHor, begVer, endVer);
    thrown[horizontal[begHor]] = false;

    thrown[vertical[begVer]] = true;
    solve(w + 1, begHor, endHor, begVer, endVer);
    thrown[vertical[begVer]] = false;

    thrown[horizontal[endHor]] = true;
    solve(w + 1, begHor, endHor, begVer, endVer);
    thrown[horizontal[endHor]] = false;

    thrown[vertical[endVer]] = true;
    solve(w + 1, begHor, endHor, begVer, endVer);
    thrown[vertical[endVer]] = false;
}

bool cmpHor(int a, int b) {
    return x[a] < x[b];
}

bool cmpVer(int a, int b) {
    return y[a] < y[b];
}

int main() {

    ios_base::sync_with_stdio(0);
    area = 4e18;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> xx >> yy >> xxx >> yyy;
        x[i] = xx + xxx;
        y[i] = yy + yyy;
    }

    for (int i = 1; i <= n; i++) {
        horizontal[i] = vertical[i] = i;
    }

    sort(horizontal + 1, horizontal + 1 + n, cmpHor);
    sort(vertical + 1, vertical + 1 + n, cmpVer);

    solve(1, 1, n, 1, n);

    if (area % 4 != 0) {
        cout << area / 4 + 1 << endl;
    } else {
        cout << area / 4 << endl;
    }

    return 0;
}