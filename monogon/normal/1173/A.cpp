
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int x, y, z;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y >> z;
    int mx = (x - y + z), mn = (x - y - z);
    if(mx == 0 && mn == 0) {
        cout << 0 << '\n';
    }else if(mn > 0) {
        cout << "+\n";
    }else if(mx < 0) {
        cout << "-\n";
    }else {
        cout << "?\n";
    }
}