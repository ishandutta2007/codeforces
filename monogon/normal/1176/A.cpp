
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        int ans = 0;
        while(n % 5 == 0) {
            ans++;
            n = 4 * (n / 5);
        }
        while(n % 3 == 0) {
            ans++;
            n = 2 * (n / 3);
        }
        while(n % 2 == 0) {
            ans++;
            n /= 2;
        }
        cout << (n == 1 ? ans : -1) << "\n";
    }
}