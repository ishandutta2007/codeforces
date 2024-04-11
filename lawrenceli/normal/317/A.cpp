#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll x, y, m;
ll num;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> x >> y >> m;
    if (x>=m || y>=m) {
        cout << 0 << endl;
        return 0;
    }
    if (x<=0 && y<=0) {
        cout << -1 << endl;
        return 0;
    }
    if (x>y) swap(x, y);
    if (x<=0) {
        ll n=-x/y+1;
        num=n;
        x+=n*y;
    }
    while (x<m && y<m) {
        if (x>y) swap(x, y);
        x=x+y;
        num++;
    }
    cout << num << endl;
}