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

const int MX = 200005;
int n, p[MX], f[MX];

ll tr (ll n) {
	return n * (n + 1) / 2;
}

void main_() {
	cin >> n;
	
	forn (i, n) {
		cin >> p[i];
		f[p[i]] = i;
	}
	
	int l = n, r = -1;
	ll res = 0;
	
	forn (i, n) {
		l = min(l, f[i]);
		r = max(r, f[i]);
		
		if (i + 1 < n && l <= f[i + 1] && f[i + 1] <= r)
			continue;
		
		int izq = i + 1 < n && f[i + 1] < l ? l - f[i + 1] - 1 : l;
		int der = i + 1 < n && f[i + 1] > r ? f[i + 1] - r - 1 : n - r - 1;
		
		int x = i + 1;
		int y = r - l + 1 - x;
		
		if (x < y) continue;
		
		int d = x - y;
		
		res += tr(d + 1);
		if (izq + 1 <= d) res -= tr(d - (izq + 1) + 1);
		if (der + 1 <= d) res -= tr(d - (der + 1) + 1);
		if (izq + der + 2 <= d) res += tr(d - (izq + 1) - (der + 1) + 1);
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