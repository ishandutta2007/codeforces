#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 10100;
const int MAXB = 63;

int n, a[MAXN], b[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        ll l, r;
        cin >> l >> r;
        for (int j=0; j<MAXB; j++) {
            if (1LL<<j & l) a[j] = 1;
            else a[j] = 0;

            if (1LL<<j & r) b[j] = 1;
            else b[j] = 0;
        }

        ll ans = 0;
        for (int j=MAXB-1; j>=0; j--)
            if (b[j]) {
                ans = (1LL<<(j+1))-1;
                for (int k=j; k>=0; k--)
                    if (!(a[k] && b[k])) {
                        if (b[k]) {
                            if ((r&((1LL<<k)-1)) != (1LL<<k)-1)
                                ans -= 1LL<<k;
                            break;
                        } else ans -= 1LL<<k;
                    }

                break;
            }

        cout << ans << '\n';
    }
}