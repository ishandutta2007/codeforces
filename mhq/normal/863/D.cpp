#include <bits/stdc++.h>
using namespace std;
struct seg {
    int t;
    int l;
    int r;
};
int n, q, m;
const int maxN = 2 * 100000 + 3;
int a[maxN];
int b[102];
int c[102];
seg r[maxN];
int main()
{   ios_base::sync_with_stdio(0);
    cin >> n >> q >> m;
    for ( int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for ( int i = 1; i <= q; i++) {
        cin >> r[i].t >> r[i].l >> r[i].r;
    }
    for ( int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for ( int i = q; i >= 1; i--) {
        for ( int j = 1; j <= m; j++) {
            if ( r[i].t == 1) {
                    if ( b[j] >= r[i].l && b[j] <= r[i].r) {
                        if ( b[j]  == r[i].l) {
                            b[j] = r[i].r;
                        }
                        else b[j]--;
                    }
            }
            else {
                if ( b[j] >= r[i].l && b[j] <= r[i].r) {
                        b[j] = r[i].l + r[i].r - b[j];
                    }
             }
        }
    }
    for ( int i = 1; i <= m; i++) {
        cout << a[b[i]] << " ";
    }
    return 0;
}