
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll r[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> r[0] >> r[1] >> r[2];
        sort(r, r + 3);
        if(r[2] > r[0] + r[1]) {
            cout << r[0] + r[1] << endl;
        }else {
            cout << (r[0] + r[1] + r[2]) / 2 << endl;
        }
    }
}