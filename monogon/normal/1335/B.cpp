
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        for(int i = 0; i < n; i++) {
            cout << (char) ('a' + ((i) % b));
        }
        cout << '\n';
    }
}