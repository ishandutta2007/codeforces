#include <bits/stdc++.h>
using namespace std;
int brute(int x) {
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (i * i - (i / j) * (i / j) == x) {
                return i;
            }
        }
    }
    return -1;
}
void solve() {
    int x;
    cin >> x;
    //int m1 = rand();
    //int n1 = (rand() % m1) + 1;
    //x = m1 * m1 - (m1 / n1) * (m1 / n1);
    if (x == 0) {
        cout << 1 << " " << 1 << '\n';
        return ;
    }
    for (int m = 1; m * m <= 2 * x; m++) {
        int need = m * m - x;
        if (need < 0) continue;
        int l = 1;
        int r = m;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if ((m / mid) * (m / mid) == need) {
                cout << m << " " << mid << '\n';
                return ;
            }
            if ((m / mid) * (m / mid) > need) l = mid;
            else r = mid;
        }
        if (need == (m / l) * (m / l)) {
            cout << m << " " << l << '\n';
            return ;
        }
        if (need == (m / r) * (m / r)) {
            cout << m << " " << r << '\n';
            return ;
        }
    }
    /*if (brute(x) != -1) {
        cout << x << " " << brute(x);
        exit(0);
    }*/
    cout << -1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    //t = 1000;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}