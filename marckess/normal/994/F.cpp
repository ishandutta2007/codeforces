#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 50;
int n, q[MX];
ll a[MX], b[MX], t, mem[MX][MX][MX];

void reset (ll m) {
    t = m;
    for (int i = 0; i < MX; i++)
        for (int j = 0; j < MX; j++)
            for (int k = 0; k < MX; k++)
                mem[i][j][k] = -1;
}

ll dp (int i, int j, int k, ll ant) {
    if (i == n)
        return 0;

    int u = q[i];
    if (a[u] != ant) {
        j += k;
        k = 0;
    }

    ll &_ = mem[i][j][k];
    if (_ != -1)
        return _;

    _ = dp(i+1, j, k+1, a[u]) + a[u] - t * b[u];
    if (j)
        _ = min(_, dp(i+1, j-1, k, a[u]));

    return _;
}

ll obtRes () {
    ll i = 0, j = 1e12, rep = 50;

    while (rep--) {
        ll m = (i+j)/2;
        reset(m);
        if (dp(0, 0, 0, 0) <= 0)
            j = m;
        else
            i = m;
    }

    reset(i);
    if (dp(0, 0, 0, 0) <= 0)
        return i;
    return j;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 1000;
    }

    for (int i = 0; i < n; i++)
        cin >> b[i];

    iota(q, q+n, 0);
    sort(q, q+n, [&] (int i, int j) {
        return a[i] > a[j];
    });

    cout << obtRes () << endl;

    return 0;
}