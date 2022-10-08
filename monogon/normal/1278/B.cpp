
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll a, b;

ll solve(ll gap) {
    ll n = ceil(0.5 * (-1 + sqrt(1 + 8 * gap)));
    while((n * (n + 1) / 2) % 2 != gap % 2) n++;
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << solve(abs(b - a)) << endl;
    }
}