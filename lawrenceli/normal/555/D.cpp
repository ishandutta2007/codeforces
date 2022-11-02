#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 200100;

int n, m;
pll ar[MAXN];
int ind[MAXN];

int lox(ll x) {
    return lower_bound(ar, ar+n, pll(x, -1))-ar;
}

int upx(ll x) {
    return lower_bound(ar, ar+n, pll(x+1, -1))-ar-1;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> ar[i].fi;
        ar[i].se = i;
    }
    sort(ar, ar+n);
    for (int i=0; i<n; i++) ind[ar[i].se] = i;

    for (int i=0; i<m; i++) {
        int a, l, d=1;
        cin >> a >> l;
        a = ind[a-1];

        while (1) {
            int b = d ? upx(ar[a].fi+l) : lox(ar[a].fi-l);

            ll x = abs(ar[a].fi-ar[b].fi);
            //assert(l >= x);

            int c = d ? lox(ar[b].fi-(l-x)) : upx(ar[b].fi+(l-x));

            if (a == b && b == c) {
                cout << ar[a].se+1 << '\n';
                break;
            }

            if (a != c) {
                a = b, l -= x, d = (d+1)%2;
                continue;
            }

            int y = (l/x+d)%2;

            a = (d == y ? a : b);
            d = y;
            l = l%x;
        }
    }
}