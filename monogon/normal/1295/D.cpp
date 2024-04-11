
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll a, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> m;
        ll n = m / gcd(a, m);
        ll phi = 1;
        for(ll i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                n /= i;
                phi *= i - 1;
                while(n % i == 0) {
                    n /= i;
                    phi *= i;
                }
            }
        }
        if(n > 1) phi *= n - 1;
        cout << phi << endl;
    }
}