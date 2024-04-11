
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int M = 1e9 + 7;
int n, m;

ll modpow(ll a, ll b) {
    a = ((a % M) + M) % M;
    ll ans = 1;
    for(int i = 0; b > 0; i++) {
        if(b % 2) {
            (ans *= a) %= M;
        }
        (a *= a) %= M;
        b /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cout << modpow(modpow(2, m) - 1, n) << endl;
}