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

typedef pair<ll, vi> Tres;

const int MX = 100005;
string s;
int n, a[MX], b[MX], acu[MX][4], cn[4];
vi pos[4];

ll go () {
	int pre[4] = {0, 0, 0, 0};
	ll res = 0;
	
	forn (i, n) {
		int in = pos[b[i]][pre[b[i]]];
		
		forn (j, 4)
			if (b[i] != j)
				res += max(0, pre[j] - acu[in][j]);
		
		pre[b[i]]++;
	}
	
	return res;
}

void solve () {
	cin >> s;
	n = s.size();
	
	memset(cn, 0, sizeof(cn));
	memset(acu[0], 0, sizeof(acu[0]));
	forn (i, 4) pos[i].clear();
	
	forn (i, n) {
		if (s[i] == 'A') a[i] = 0;
		if (s[i] == 'N') a[i] = 1;
		if (s[i] == 'O') a[i] = 2;
		if (s[i] == 'T') a[i] = 3;
		
		cn[a[i]]++;
		
		if (i)
			forn (j, 4)
				acu[i][j] = acu[i - 1][j];
		acu[i][a[i]]++;
		
		pos[a[i]].pb(i);
	}
	
	Tres res(-1, {});
	vi ord = {0, 1, 2, 3};
	do {
		int m = 0;
		forn (i, 4)
			forn (kk, cn[ord[i]])
				b[m++] = ord[i];
		
		Tres p(go(), ord);
		res = max(res, p);
	} while (next_permutation(all(ord)));
	
	forn (i, 4)
		forn (kk, cn[res.se[i]]) {
			if (res.se[i] == 0) cout << "A";
			if (res.se[i] == 1) cout << "N";
			if (res.se[i] == 2) cout << "O";
			if (res.se[i] == 3) cout << "T";
		}
	cout << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}