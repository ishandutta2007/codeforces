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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, res[MX];
ii p[MX];

ii operator - (const ii &a, ii const &b) {
	return {a.fi - b.fi, a.se - b.se};
}

ll operator % (const ii &a, const ii &b) {
	return a.fi * b.fi + a.se * b.se;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n)
		cin >> p[i].fi >> p[i].se;
		
	forn (i, n) {
		res[i] = i;
		
		for (int j = i - 2; j >= 0; j--) {
			if ((p[res[j + 2]] - p[res[j + 1]]) % (p[res[j]] - p[res[j + 1]]) <= 0)
				swap(res[j + 1], res[j + 2]);
			else break;
		}
	}
	
	forn (i, n) cout << res[i] + 1 << " ";
	cout << endl;
			
	return 0;
}