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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, m, d[MX], h[MX], res = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> d[i] >> h[i];

    res = max(res, h[0] + d[0] - 1);
    res = max(res, h[m-1] + n - d[m-1]);

    for (int i = 1; i < m; i++) {
        if (abs(d[i] - d[i-1]) < abs(h[i] - h[i-1])) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        res = max(res, max(h[i], h[i-1]) + ((d[i] - d[i-1]) - abs(h[i] - h[i-1])) / 2);
    }

    cout << res << endl;
    
    return 0;
}