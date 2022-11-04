#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, a, b, c, m;
    vi acu;

    cin >> n >> m;
    acu = vi(n+1);

    while (m--) {
        cin >> a >> b >> c;
        acu[a] -= c;
        acu[b] += c;
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (acu[i] > 0)
            res += ll(acu[i]);
    }

    cout << res << endl;

    return 0;
}