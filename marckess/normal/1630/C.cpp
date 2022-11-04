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

const int MX = 200005;
int n, a[MX], ini[MX], fin[MX], c[MX];

void main_() {
	cin >> n;
	
	memset(ini, -1, sizeof(ini));
	memset(fin, -1, sizeof(fin));
	
	forn (i, n) {
		cin >> a[i];
		if (ini[a[i]] == -1)
			ini[a[i]] = i;
		fin[a[i]] = i;
	}
 	
	int mx = -1, nex = -1, i = 0, res = 0;
	while (i < n) {
		if (mx == -1) {
			if (fin[a[i]] != i)
				mx = fin[a[i]];
			i++;
		} else if (i < mx) {
			if (fin[a[i]] > mx)
				nex = max(nex, fin[a[i]]);
			res += !c[i];
			c[i] = 1;
			i++;
		} else {
			if (nex != -1) {
				i = ini[a[nex]];
				res -= c[i];
				c[i] = 0;
				i++;
				
				mx = nex;
				nex = -1;
			} else {
				mx = -1;
				i++;
			}
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}