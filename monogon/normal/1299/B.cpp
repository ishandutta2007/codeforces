
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5 ;
int n;
ll x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    if(n % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        int i2 = (i + 1) % n;
        int j = (i + n / 2) % n;
        int j2 = (j + 1) % n;
        ll dx = x[i2] - x[i];
        ll dy = y[i2] - y[i];
        ll dx2 = x[j2] - x[j];
        ll dy2 = y[j2] - y[j];
        if(dx != -dx2 || dy != -dy2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}