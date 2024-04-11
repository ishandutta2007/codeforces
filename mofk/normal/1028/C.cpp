#include <bits/stdc++.h>

using namespace std;

int n;
int x[200005], y[2000005], u[200005], v[200005];
int mnx[200005], mxx[200005], mny[200005], mxy[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i] >> u[i] >> v[i];
    mnx[0] = mny[0] = 1e9 + 1;
    mxx[0] = mxy[0] = -(1e9 + 1);
    for (int i = 1; i <= n; ++i) {
        mnx[i] = min(mnx[i-1], u[i]);
        mxx[i] = max(mxx[i-1], x[i]);
        mny[i] = min(mny[i-1], v[i]);
        mxy[i] = max(mxy[i-1], y[i]);
    }
    int X = -1e9 - 1, Y = -1e9 - 1, U = 1e9 + 1, V = 1e9 + 1;
    for (int i = n + 1; i >= 2; --i) {
        if (max(X, mxx[i-2]) <= min(U, mnx[i-2]) && max(Y, mxy[i-2]) <= min(V, mny[i-2])) {
            cout << max(X, mxx[i-2]) << ' ' << max(Y, mxy[i-2]) << endl;
            return 0;
        }
        X = max(X, x[i-1]);
        Y = max(Y, y[i-1]);
        U = min(U, u[i-1]);
        V = min(V, v[i-1]);
    }
    return 0;
}