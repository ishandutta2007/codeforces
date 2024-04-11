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

int k, n, a[100005], t[100005], res = 0, mx = 0, acu = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    for (int i = 0; i < n; i++) {
    	cin >> t[i];
    	res += a[i] * t[i];
    	t[i] = 1 - t[i];
    }

    for (int i = 0; i < n; i++) {
    	acu += a[i] * t[i];
    	if (i - k >= 0)
    		acu -= a[i-k] * t[i-k];
    	mx = max(mx, acu);
    }

    cout << res + mx << endl;

    return 0;
}