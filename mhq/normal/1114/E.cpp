#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
int asked = 0;
int mx = 124124;
int d = 1244;
int ask1(int x) {
    cout << "? " << x << endl;
    // return mx - (x - 1) * d;
    int ans;
    cin >> ans;
    return ans;
}
int ask2(int y) {
 //   if (y >= mx) return 0;
 //   else return 1;
    asked++;
    cout << "> " << y << endl;
    int c;
    cin >> c;
    return c;
}
mt19937 rnd(228);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int r = 1000 * 1000 * 1000;
    int l = 0;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask2(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    int mx = l + 1;
    int d = 0;
    for (int i = 0; i < 60 - asked - 2; i++) {
        int ind = rnd() % n + 1;
        int val = ask1(ind);
        d = gcd(d, mx - val);
    }
    cout << "! " << mx - (n - 1) * d << " " << d << endl;
}