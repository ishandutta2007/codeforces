
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x;
    for(ll i = round(sqrt(x)); i >= 1; i--) {
        if(x % i == 0 && gcd(i, x / i) == 1) {
            cout << i << " " << (x / i) << endl;
            break;
        }
    }
}