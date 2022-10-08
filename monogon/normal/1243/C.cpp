
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll p = 1;
    bool b = false;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            p = i;
            while(n % i == 0) {
                n /= i;
            }
            b = true;
            break;
        }
    }
    cout << (!b ? n : n == 1 ? p : 1) << endl;
}