#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, k[MX], cn[MX], res[MX];
vi f[MX];

void solve () {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cn[i] = 0;
	
	forn (i, m) {
		cin >> k[i];
		
		f[i] = vi(k[i]);
		for (int &x : f[i])
			cin >> x;
		
		res[i] = f[i][0];
		cn[res[i]]++;
	}
	
	int ind = 1;
	for (int i = 1; i <= n; i++)
		if (cn[i] > cn[ind])
			ind = i;
	
	if (cn[ind] > (m + 1) / 2) {
		forn (i, m) {
			if (res[i] == ind && f[i].size() > 1) {
				res[i] = f[i][1];
				cn[ind]--;
				
				if (cn[ind] <= (m + 1) / 2)
					break;
			}
		}
	}
	
	if (cn[ind] > (m + 1) / 2) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		forn (i, m)
			cout << res[i] << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}