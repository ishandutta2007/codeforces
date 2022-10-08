
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll a, b, c, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> r;
        if(a > b) swap(a, b);
        cout << max(0LL, min(c - r, b) - a) + max(0LL, b - max(a, c + r)) << endl;
    }
}