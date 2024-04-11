
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, h, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> h >> m;
        cout << (24 * 60 - 60 * h - m) << endl;
    }
}