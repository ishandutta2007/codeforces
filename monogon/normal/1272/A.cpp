
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll a[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << max(0LL, 2 * (a[2] - a[0] - 2)) << endl;
    }
}