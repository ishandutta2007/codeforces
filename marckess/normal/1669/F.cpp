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
int n, a[MX];
ll acu[MX];

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		
		acu[i] = a[i];
		if (i) acu[i] += acu[i - 1];
	}
	
	int res = 0;
	ll s = 0;
	for (int i = n - 1; i > 0; i--) {
		s += a[i];
		
		int j = lower_bound(acu, acu + i, s) - acu;
		
		if (j < i && acu[j] == s)
			res = max(res, (j + 1) + (n - i));
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