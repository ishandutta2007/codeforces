#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
ll n, a[MX], ind = 0, mx = 0, s = 0;
vi res;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];

        if (a[i] > mx) {
            mx = a[i];
            ind = i;
        }
    }

    for (int i = 0; i < n; i++)
        if (i != ind)
            if (2 * mx == s - a[i])
                res.pb(i+1);

    ll seg = 0;
    for (int i = 0; i < n; i++)
        if (i != ind) 
            seg = max(seg, a[i]);

    if (2 * seg == s - mx)
        res.pb(ind+1);

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}