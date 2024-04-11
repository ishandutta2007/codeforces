
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << (n % m == 0 ? "YES" : "NO") << "\n";
    }
}