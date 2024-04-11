#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pr pair<int, int>
using namespace std;
void rmain() {
    int n;
    cin >> n;
    int r[3], c[3], x, y;
    FOR(i, 0, 2) cin >> r[i] >> c[i];
    cin >> x >> y;
    int mr = r[0], mc = c[0];
    FOR(i, 1, 2) mr = min(mr, r[i]), mc = min(mc, c[i]);
    int corn = 1;
    FOR(i, 0, 2) if(r[i] == 1 || r[i] == n || c[i] == 1 || c[i] == n) {

    } else corn = 0;
    if(corn) {
        int rx = -1, ry = -1;
        FOR(i, 0, 2) {
            if(r[i] == 1 || r[i] == n) rx = r[i];
            if(c[i] == 1 || c[i] == n) ry = c[i];
        }
        if(x == rx || y == ry) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    int X = 0, Y = 0;
    FOR(i, 0, 2) X ^= r[i], Y ^= c[i];
    if((x - X) % 2 || (y - Y) % 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    // x * x x * x + x * 2
    // 2 * x + 1
    int t;
    for(cin >> t; t--; ) rmain();
    return 0;
}