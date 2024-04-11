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

const int MX = 405;
int n, m, r, c;
bitset<MX> bs[26][MX], res[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n)
		forn (j, m) {
			char c;
			cin >> c;
			
			bs[c - 'a'][i][j] = 1;
			res[i][j] = 1;
		}
	
	cin >> r >> c;
	forn (i, r)
		forn (j, c) {
			char h;
			cin >> h;
		
			if (h != '?') {
				int oy = MOD(-j, m);
				for (int k = 0; k < n; k++)
					res[MOD(k - i, n)] &=
						(bs[h - 'a'][k] << oy) | 
						(bs[h - 'a'][k] >> (m - oy));
			}
		}
	
	forn (i, n) {
		forn (j, m)
			cout << int(res[i][j]);
		cout << endl;
	}
	
	return 0;
}