#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll)1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll x_l = INF;
    ll x_r = -INF;
    ll y_u = INF;
    ll y_d = -INF;
    ll x_l_u = INF;
    ll x_l_d = INF;
    ll x_r_u = -INF;
    ll x_r_d = -INF;
    int n;
    cin >> n;
    vector<char> type(n);
    vector<ll> x(n);
    vector<ll> y(n);
    ll x0, y0;
    cin >> x0 >> y0;
    for (int i = 0; i < n; i++) {
        cin >> type[i] >> x[i] >> y[i];
        x[i] -= x0;
        y[i] -= y0;
        if (y[i] == 0 && x[i] > 0) {
            x_l = min(x_l, x[i]);
        } else if (y[i] == 0 && x[i] < 0) {
            x_r = max(x_r, x[i]);
        } else if (x[i] == 0 && y[i] > 0) {
            y_u = min(y_u, y[i]);
        } else if (x[i] == 0 && y[i] < 0) {
            y_d = max(y_d, y[i]); 
        } else if (x[i] == y[i] && x[i] > 0) {
            x_l_u = min(x_l_u, x[i]);
        } else if (x[i] == -y[i] && x[i] > 0) {
            x_l_d = min(x_l_d, x[i]);
        } else if (x[i] == y[i] && x[i] < 0) {
            x_r_d = max(x_r_d, x[i]);
        } else if (x[i] == -y[i] && x[i] < 0) {
            x_r_u = max(x_r_u, x[i]);
        }
    }
    bool beats = false;
    for (int i = 0; i < n; i++) {
        if (y[i] == 0 && x[i] > 0) {
            if (x[i] == x_l && (type[i] == 'R' || type[i] == 'Q'))
                beats = true;
        } else if (y[i] == 0 && x[i] < 0) {
            if (x[i] == x_r && (type[i] == 'R' || type[i] == 'Q'))
                beats = true;
        } else if (x[i] == 0 && y[i] > 0) {
            if (y[i] == y_u && (type[i] == 'R' || type[i] == 'Q'))
                beats = true;
        } else if (x[i] == 0 && y[i] < 0) {
            if (y[i] == y_d && (type[i] == 'R' || type[i] == 'Q'))
                beats = true;
        } else if (x[i] == y[i] && x[i] > 0) {
            if (x[i] == x_l_u && (type[i] == 'B' || type[i] == 'Q'))
                beats = true;
        } else if (x[i] == -y[i] && x[i] > 0) {
             if (x[i] == x_l_d && (type[i] == 'B' || type[i] == 'Q'))
                beats = true;
        } else if (x[i] == y[i] && x[i] < 0) {
             if (x[i] == x_r_d && (type[i] == 'B' || type[i] == 'Q'))
                beats = true;
        } else if (x[i] == -y[i] && x[i] < 0) {
             if (x[i] == x_r_u && (type[i] == 'B' || type[i] == 'Q'))
                beats = true;
        }
    }
    cout << (beats ? "YES" : "NO") << endl;
}