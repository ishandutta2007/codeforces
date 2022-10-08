
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
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << (i == 0 && j == 0 ? 'W' : 'B');
            }
            cout << '\n';
        }
    }
}