// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10005;
int n, m, x[11], acu[MX], cn[22];
ll sum[MX];
string s[11];
vi res;

void main_() {
	cin >> n >> m;
	forn (i, n) cin >> x[i];
	forn (i, n) cin >> s[i];
	
	ll mx = -1e18;
	int rm;
	
	forn (mk, 1 << n) {
		memset(acu, 0, sizeof(acu));
		ll p = 0;
		
		forn (i, n) {
			int d = 0;
			
			if (mk & (1 << i)) {
				p -= x[i];
				d = 1;
			} else {
				p += x[i];
				d = -1;
			}
			
			forn (j, m)
				if (s[i][j] == '1')
					acu[j] += d;
		}
		
		memset(cn, 0, sizeof(cn));
		forn (j, m)
			cn[acu[j] + 10]++;
		
		for (int i = 20, x = 10, t = m; i >= 0; i--, x--) {
			p += x * sum[t];
			t -= cn[i];
			p -= x * sum[t];
		}
		
		if (mx < p) {
			mx = p;
			rm = mk;
		}
	}
	
	vii v(m);
	forn (i, m)
		v[i].se = i;
	
	forn (i, n) {
		int d = (rm & (1 << i)) ? 1 : -1;
		
		forn (j, m)
			if (s[i][j] == '1')
				v[j].fi += d;
	}
	
	sort(all(v));
	vi res(m);
	
	forn (i, m)
		res[v[i].se] = i + 1;
	forn (i, m)
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	forn (i, MX) {
		sum[i] = i;
		if (i) sum[i] += sum[i - 1];
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}