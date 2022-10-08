
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
const ll INF = 1e9;
int n;
ll x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll mx = INF, my = INF, Mx = -INF, My = -INF;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        mx = min(mx, x[i]);
        Mx = max(Mx, x[i]);
        my = min(my, y[i]);
        My = max(My, y[i]);
    }
    ll p3 = 0;
    for(int i = 0; i < 4; i++) {
        ll X = (i & 1 ? mx : Mx);
        ll Y = (i / 2 ? my : My);
        for(int j = 0; j < n; j++) {
            p3 = max(p3, 2 * abs(X - x[j]) + 2 * abs(Y - y[j]));
        }
    }
    cout << p3;
    ll p4 = 2 * (Mx - mx) + 2 * (My - my);
    for(int i = 4; i <= n; i++) {
        cout << " " << p4;
    }
    cout << endl;
}