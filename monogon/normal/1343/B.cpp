
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 1 + 5 = 2 + 4

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        if((n / 2) % 2 == 1) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for(int i = 0; i < n / 2; i += 2) {
            cout << 3 * i + 2 << " " << 3 * i + 4 << " ";
        }
        for(int i = 0; i < n / 2; i += 2) {
            cout << 3 * i + 1 << " " << 3 * i + 5 << " ";
        }
        cout << '\n';
    }
}