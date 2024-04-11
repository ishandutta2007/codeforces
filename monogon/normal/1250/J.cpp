
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << (__gcd(a, b) == 1 ? "Finite" : "Infinite") << endl;
    }
}