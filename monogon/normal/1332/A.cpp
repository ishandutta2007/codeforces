
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, a, b, c, d, x, y, X1, Y1, X, Y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d >> x >> y >> X1 >> Y1 >> X >> Y;
        int dx = b - a;
        int dy = d - c;
        if((a != 0 || b != 0) && X == X1) {
            cout << "NO\n";
        }else if((c != 0 || d != 0) && Y == Y1) {
            cout << "NO\n";
        }else {
            cout << (x + dx >= X1 && x + dx <= X && y + dy >= Y1 && y + dy <= Y ? "YES" : "NO") << '\n';
        }
    }
}