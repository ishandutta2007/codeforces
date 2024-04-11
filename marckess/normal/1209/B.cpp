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

const int MX = 100005;
int n, cn[MX], a[MX], b[MX];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];

		int f = s[i] - '0';
		for (int j = 0; j < MX; j++) {
			if (j == b[i]) {
				b[i] += a[i];
				f = 1 - f;
			}
			cn[j] += f;
		}
	}

	int res = 0;
	for (int i = 0; i < MX; i++)
		res = max(res, cn[i]);
	cout << res << endl;

	return 0;
}