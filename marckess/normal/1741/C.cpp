#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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


const int MX = 20005;
int n, a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	int res = n;
	forn (i, n) {
		int s = 0;
		forn (j, i + 1)
			s += a[j];
		int mx = i + 1, acu = 0, cn = 0;
		for (int j = i + 1; j < n; j++) {
			acu += a[j];
			cn++;
			if (acu == s) {
				mx = max(mx, cn);
				acu = 0;
				cn = 0;
			}
		}
		if (cn == 0)
			res = min(res, mx);
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}