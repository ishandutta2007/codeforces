// Powered by CP Editor (https://cpeditor.org)

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
int n, q, a[MX];
ll pre[MX], ned[MX], mx[MX];

ll ceil (ll a, ll b) {
	return (a + b - 1) / b;
}

void main_() {
	cin >> n;
	
	forr (i, 1, n) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		ned[i] = ceil(pre[i], i);
		mx[i] = max(ned[i], mx[i - 1]);
	}
	
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		
		ll res = ceil(pre[n], t);
		if (res > n) cout << -1 << endl;
		else if (mx[res] > t) cout << -1 << endl;
		else cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}