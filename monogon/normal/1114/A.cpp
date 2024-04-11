
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int x, y, z, a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y >> z >> a >> b >> c;
    if(a < x) {
        cout << "NO\n";
        return 0;
    }
    a -= x;
    if(a + b < y) {
        cout << "NO\n";
        return 0;
    }
    b -= max(0, y - a);
    a = max(0, a - y);
    if(a + b + c < z) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
}