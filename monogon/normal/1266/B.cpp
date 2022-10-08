
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x;
        if(x >= 15 && (x % 14) >= 1 && (x % 14) <= 6) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
}