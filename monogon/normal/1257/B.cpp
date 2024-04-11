
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int T;
ll x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> x >> y;
        if(x == 1 && y > 1 || (x <= 3 && y > 3)) {
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;
        }
    }
}