#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, bx, m, by;
    cin >> n >> bx;
    ll x = 0;
    for (int i = 0; i < n; i++) {
        x *= bx;
        int a; cin >> a;
        x += a;
    }

    cin >> m >> by;
    ll y = 0;
    for (int i = 0; i < m; i++) {
        y *= by;
        int a; cin >> a;
        y += a;
    }
    
    if (x < y) cout << "<\n";
    else if (x > y) cout << ">\n";
    else cout << "=\n";
}