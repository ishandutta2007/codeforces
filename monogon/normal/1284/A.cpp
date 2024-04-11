
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 30;
int n, m, q, y;
string s[N], t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> t[i];
    }
    cin >> q;
    while(q--) {
        cin >> y;
        y--;
        cout << s[y % n] << t[y % m] << endl;
    }
}