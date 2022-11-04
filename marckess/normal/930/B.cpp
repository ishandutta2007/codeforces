#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, cn[26], acu[26][MX][26], a[MX];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
		a[i] = s[i]-'a';

	for (int i = 0; i < n; i++) {
		cn[a[i]]++;
		for (int j = 0, l = (i+1)%n; j < n-1; j++, l++, l = (l == n ? 0 : l))
			acu[a[i]][j][a[l]]++;
	}

	int res = 0;
	for (int i = 0; i < 26; i++) {
		if (!cn[i]) continue;
		int mx = 0;
		for (int j = 0; j < n-1; j++) {
			int p = 0;
			for (int k = 0; k < 26; k++)
				if (acu[i][j][k] == 1)
					p++;
			mx = max(mx, p);
		}
		res += mx;
	}

	cout << (ld)res / n << endl;

	return 0;
}