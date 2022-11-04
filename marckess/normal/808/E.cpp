#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m, w, c;
ll mx[300005] = {0}, cn[300005][3] = {0};
vi a[4];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w >> c;
        a[w].push_back(c);
    }

    for (int i = 1; i < 4; i++)
        sort(ALL(a[i]), greater<int>());

    mx[0] = cn[0][1] = cn[0][2] = 0;

    for (int i = 0; i < m; i++) {
        if (cn[i][1] < a[1].size())
            if (mx[i+1] < mx[i] + a[1][cn[i][1]]) 
                mx[i+1] = mx[i] + a[1][cn[i][1]], cn[i+1][1] = cn[i][1] + 1, cn[i+1][2] = cn[i][2];

        if (cn[i][2] < a[2].size())
            if (mx[i+2] < mx[i] + a[2][cn[i][2]])
                mx[i+2] = mx[i] + a[2][cn[i][2]], cn[i+2][1] = cn[i][1], cn[i+2][2] = cn[i][2] + 1;
    }

    for (int i = 1; i <= m; i++)
        mx[i] = max(mx[i], mx[i-1]);

    ll res = mx[m], acu = 0;
    for (int i = 0; i < a[3].size() && (i + 1) * 3 <= m; i++) {
        acu += a[3][i];
        res = max(res, acu + mx[m - (i + 1) * 3]);
    }

    cout << res << endl;

    return 0;
}