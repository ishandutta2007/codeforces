#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll gcd(ll a, ll b){
    a = abs(a);
    b = abs(b);
    if (a == 0) return b;
    else if (b == 0) return a;
    ll newa = b % a;
    ll newb = a;
    ll placeholder;
    while (newa != 0) {
        placeholder = newa;
        newa = newb % newa;
        newb = placeholder;
    }
    return newb;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> nums(n);
    ll shift;
    cin >> shift;
    k -= shift;
    nums[0] = 0;
    ll g;
    cin >> g;
    g -= shift;
    nums[1] = g;
    for (int i = 2; i < n; i++) {
        cin >> nums[i];
        nums[i] -= shift;
        g = gcd(g, nums[i]);
    }
    if (k%g==0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}