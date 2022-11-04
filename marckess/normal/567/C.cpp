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
int n;
ll a[MX], k, res = 0;
map<ll, ll> mp, acu;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        res += acu[a[i]*k];
        acu[a[i]] += mp[a[i]*k];
        mp[a[i]]++;
    }

    cout << res << endl;

    return 0;
}