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
int n, a[MX], pre[MX], suf[MX];

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		if (pre[i - 1] == -1) pre[i] = -1;
		else {
			pre[i] = a[i] - pre[i - 1];
			if (pre[i] < 0)
				pre[i] = -1;
		} 
	}
	
	if (pre[n] == 0) {
		cout << "YES" << endl;
		return;
	}
	
	suf[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		if (suf[i + 1] == -1) suf[i] = -1;
		else {
			suf[i] = a[i] - suf[i + 1];
			if (suf[i] < 0)
				suf[i] = -1;
		}
	}
	
	for (int i = 1; i + 1 <= n; i++) {
		if (pre[i - 1] == -1 || suf[i + 2] == -1) continue;
		
		vi v = {pre[i - 1], a[i + 1], a[i], suf[i + 2]};
		
		for (int i = 1; i < 4; i++) {
			if (v[i - 1] == -1) v[i] = -1;
			else {
				v[i] -= v[i - 1];
				if (v[i] < 0)
					v[i] = -1;
			}
		}
		
		if (v[3] == 0) {
			cout << "YES" << endl;
			return;
		}
	}
	
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}