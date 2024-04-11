#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, imp[MX], sz[MX];
string s, last, res[MX], acu;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();
	
	int cn = 0;
	
	forn (i, n) {
		if (i && s[i] != s[i - 1]) {
			if (cn & 1) imp[i - cn] = 1;
			cn = 0;
		}
		cn++;
	}
	
	if (cn & 1) imp[n - cn] = 1;
	
	for (int i = n - 1, t = 0, last = int('a') - 1, ant = last; i >= 0; i--) {
		if (imp[i]) {
			if (acu.size() && s[i] != last) ant = last;
			acu.pb(s[i]);
			t = 0;
			last = s[i];
		} else {
			if (t % 2 == 0) {
				acu.pb(s[i]);
				t++;
			} else if (s[i] > last) {
				acu.pop_back();
				t--;
			} else if (s[i] == last && last > ant) {
				acu.pop_back();
				t--;
			} else {
				if (acu.size() && s[i] != last) ant = last;
				acu.pb(s[i]);
				last = s[i];
				t++;
			}
		}
		
		sz[i] = acu.size();
		if (sz[i] <= 10) {
			res[i] = acu;
			reverse(all(res[i]));
		} else {
			for (int j = int(acu.size() - 1); j + 5 >= acu.size(); j--)
				res[i].pb(acu[j]);
			res[i] += "...";
			res[i].pb(acu[1]);
			res[i].pb(acu[0]);
		}
	}
	
	forn (i, n) cout << sz[i] << " " << res[i] << endl;
	
	return 0;
}