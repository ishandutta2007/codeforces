#include <bits/stdc++.h>
using namespace std;
int x[4];
int y[4];
int a[4];
int b[4];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
        x[i] *= 2;
        y[i] *= 2;
    }
    for (int j = 0; j < 4; j++) {
        cin >> a[j] >> b[j];
        a[j] *= 2;
        b[j] *= 2;
    }
    int cenx = (a[0] + a[2]) / 2;
    int ceny = (b[0] + b[2]) / 2;
    int mnx = x[0];
    int mny = y[0];
    int mxx = x[0];
    int mxy = y[0];
    for (int i = 0; i < 4; i++) {
        mnx = min(mnx, x[i]);
        mxx = max(mxx, x[i]);
        mny = min(mny, y[i]);
        mxy = max(mxy, y[i]);
    }
    int dist = (abs(a[0] - cenx) + abs(b[0] - ceny));
    int valx = min(abs(mnx - cenx), abs(mxx - cenx));
    int valy = min(abs(mny - ceny), abs(mxy - ceny));
    if (mnx <= cenx && cenx <= mxx) valx = 0;
    if (mny <= ceny && ceny <= mxy) valy = 0;
    //cout << valx << " " << valy << " " << dist << endl;
    if (valx + valy <= dist) cout << "YES";
    else cout << "NO";
    return 0;
}