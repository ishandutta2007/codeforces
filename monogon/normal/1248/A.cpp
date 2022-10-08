
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, m;
ll p, e1, e2, o1, o2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        e1 = e2 = o1 = o2 = 0;
        for(int i = 0; i < n; i++) {
            cin >> p;
            ((p & 1) ? e1 : o1)++;
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> p;
            ((p & 1) ? e2 : o2)++;
        }
        cout << (e1 * e2) + (o1 * o2) << endl;
    }
}