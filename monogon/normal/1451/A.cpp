
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int te;
    cin >> te;
    while(te--) {
        ll n;
        cin >> n;
        ll ans;
        if(n <= 3) ans = n - 1;
        else {
            ans = 2 + (n % 2);
        }
        cout << ans << '\n';
    }
}