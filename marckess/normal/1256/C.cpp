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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, d, res[MX], c[MX], acu[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++)
		cin >> c[i];

	for (int i = m; i >= 1; i--)
		acu[i] = c[i] + acu[i+1];

	int act = -1;
	for (int i = 1; i <= m; i++) {
		int nex = min(act + d, n - acu[i]);
		while (c[i]--) {
			res[nex] = i;
			nex++;
		}
		act = nex - 1;
	}

	res[n] = m + 1;
	for (int i = 0; i < n; i++)
		if (res[i] && res[i] != res[i + 1]) {
			int nex = i + 1;
			while (!res[nex])
				nex++;
			if (nex - i > d) {
				cout << "NO" << endl;
				return 0;
			}
		}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}