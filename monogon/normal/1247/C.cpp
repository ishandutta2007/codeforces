
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n;
int p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    for(int k = 1; k < 40; k++) {
        ll m = n - p * k;
        if(m >= k && __builtin_popcount(m) <= k) {
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}