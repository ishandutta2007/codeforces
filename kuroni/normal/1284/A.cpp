#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, m, q;
string s[N], t[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    cin >> q;
    while (q--) {
        int i;
        cin >> i; i--;
        cout << s[i % n] << t[i % m] << '\n';
    }
}