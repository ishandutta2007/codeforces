#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
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
int n, m, mx[MX], mn[MX], sum[MX], suf_mx[MX], suf_mn[MX];
string s;

void solve () {
	cin >> n >> m >> s;
	
	mx[0] = mn[0] = sum[0] = 0;
	forn (i, n) {
		if (i) {
			mx[i] = mx[i - 1];
			mn[i] = mn[i - 1];
			sum[i] = sum[i - 1];
		}
		
		if (s[i] == '+') {
			sum[i]++;
			mx[i] = max(mx[i], sum[i]);
		} else {
			sum[i]--;
			mn[i] = min(mn[i], sum[i]);
		}
	}
	
	suf_mx[n] = suf_mn[n] = 0;
	for (int i = n - 1, sum = 0; i >= 0; i--) {
		suf_mx[i] = suf_mx[i + 1];
		suf_mn[i] = suf_mn[i + 1];
		
		if (s[i] == '+') {
			suf_mx[i]++;
			suf_mn[i] = min(0, suf_mn[i] + 1);
		} else {
			suf_mx[i] = max(0, suf_mx[i] - 1);
			suf_mn[i]--;
		}
	}
	
	while (m--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		
		if (l == 0 && r == n - 1) {
			cout << 1 << endl;
		} else if (r == n - 1) {
			cout << mx[l - 1] - mn[l - 1] + 1 << endl;
		} else if (l == 0) {
			cout << suf_mx[r + 1] - suf_mn[r + 1] + 1 << endl;
		} else {
			int a = min(mn[l - 1], sum[l - 1] + suf_mn[r + 1]);
			int b = max(mx[l - 1], sum[l - 1] + suf_mx[r + 1]);
			cout << b - a + 1 << endl;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}