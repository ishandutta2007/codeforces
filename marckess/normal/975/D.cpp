#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<ii, ll> iii;

const int MX = 200005;
map<ll, int> mp;

map<ii, int> ix;
map<ii, int> iy;
map<iii, int> ico;

ll res = 0, a, b, x, vx, vy;
int n;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> x >> vx >> vy;

        ll d = vy - a * vx;

        res += mp[vy - a * vx]++;
        
        res -= ix[ii(vx, d)]++;
        res -= iy[ii(vy, d)]++;
        res += ico[iii(ii(vx, vy), d)]++;
    }

    res *= 2;

    cout << res << endl;

    return 0;
}