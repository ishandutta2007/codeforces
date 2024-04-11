#include <bits/stdc++.h>
using namespace std;
int n;
int a[25];
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool leap(int y) {
    if (y % 400 == 0) return true;
    if ((y % 4 == 0) && (y % 100 != 0)) return true;
    return false;
}
bool ok(int t, int y, int m) {
    if (m != 2) {
        if (month[m] != a[t]) return false;
        return true;
    }
    if (m == 2 && leap(y)) {
        if (a[t] == 29) return true;
        return false;
    }
    return (a[t] == 28);
}
bool check(int i, int j) {
    int curyear = i;
    int curm = j;
    for (int t = 1; t <= n; t++) {
        if (!(ok(t, curyear, curm))) return false;
        if (curm == 12) {
            curm = 1;
            curyear++;
        }
        else curm++;
    }
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= 2000; i++) {
        for (int j = 1; j <= 12; j++) {
            if (check(i, j)) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}