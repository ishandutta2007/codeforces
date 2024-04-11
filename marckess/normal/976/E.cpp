#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 200005;
int n, a, b, hp[MX], dmg[MX], q[MX];
bitset<MX> bs;
ll res = 0, mn = -1;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> hp[i] >> dmg[i];

    iota(q, q+n, 0);
    sort(q, q+n, [&] (int x, int y) {
        return hp[x] - dmg[x] > hp[y] - dmg[y];
    });

    for (int i = 0; i < n; i++) {
        int u = q[i];

        if (hp[u] > dmg[u] && b) {
            res += hp[u];
            bs[u] = 1;
            b--;
            mn = u;
        } else {
            res += dmg[u];
        }
    }

    if (!b && mn == -1) {
        cout << res << endl;
        return 0;
    }

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll acu;

        acu = hp[i];
        for (int j = 0; j < a; j++)
            acu *= 2;

        if (bs[i]) {
            acu -= hp[i];
        } else {
            acu -= dmg[i];

            if (!b) {
                acu -= hp[mn];
                acu += dmg[mn];
            }
        }

        mx = max(mx, acu);
    }

    cout << res + mx << endl;

    return 0;
}