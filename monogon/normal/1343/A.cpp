
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n;

// n = (2^k - 1) x, k > 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int k = 2; ; k++) {
            if(n % ((1 << k) - 1) == 0) {
                cout << n / ((1 << k) - 1) << '\n';
                break;
            }
        }
    }
}