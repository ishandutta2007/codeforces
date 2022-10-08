
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n, x, y;
bool l, d, r, u;
int minx, maxx, miny, maxy;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        minx = miny = -1e5;
        maxx = maxy = 1e5;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x >> y >> l >> d >> r >> u;
            if(!l) minx = max(minx, x);
            if(!r) maxx = min(maxx, x);
            if(!u) miny = max(miny, y);
            if(!d) maxy = min(maxy, y);
        }
        // cout << "(" << minx << ", " << maxx << ") (" << miny << ", " << maxy << ")" << endl;
        if(minx <= maxx && miny <= maxy) {
            cout << "1 " << minx << " " << miny << endl;
        }else {
            cout << 0 << endl;
        }
    }
}