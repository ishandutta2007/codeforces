
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << (n / k) * k + min(n % k, k / 2) << endl;
    }
}