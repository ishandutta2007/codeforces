#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int res = 0, acu = 0, f = 0, n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') acu++;
		else acu--;

		if (acu < 0 || acu == 0 && f == 1)
			res++;
		f = acu < 0;
	}

	if (acu) cout << -1 << endl;
	else cout << res << endl; 

	return 0;
}