
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        bool e[2] = {true, true};
        for(int i = 0; i < n; i++) {
            cin >> a;
            e[a % 2] = false;
        }
        cout << (e[0] || e[1] ? "YES" : "NO") << endl;
    }
}