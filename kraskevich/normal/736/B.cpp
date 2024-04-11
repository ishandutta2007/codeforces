#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) 
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    if (is_prime(n)) {
        cout << 1 << endl;
    } else if (n % 2 == 0 || is_prime(n - 2)) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
}