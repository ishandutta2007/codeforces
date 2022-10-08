
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ll n, k, t;
    cin >> n >> k >> t;
    ll R = min(n, t);
    ll L = max(1LL, t - k + 1);
    cout << R - L + 1 << '\n';
}