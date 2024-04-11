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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
ll n, p, k, cn[MX];
int l[MX];
int a[MX];
queue<int> q[MX];

void solve () {
	cin >> n >> p >> k;
	
	for (int i = 0; i < k; i++) {
		while (q[i].size())
			q[i].pop();
		l[i] = i;
		cn[i] = 0;
	}

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);

	ll acu = 0, res = 0;
	for (int i = 0; i <= n; i++) {
		int j = (i + k - 1) % k;

		while (q[j].size() && q[j].front() < i) {
			cn[j] -= a[q[j].front()];
			q[j].pop();
		}

		l[j] = max(1ll* l[j], i + k - 1);
		while (l[j] < n && acu + cn[j] + a[l[j]] <= p) {
			cn[j] += a[l[j]];
			q[j].push(l[j]);
			l[j] += k;
		}


		if (acu + cn[j] <= p)
			res = max(res, i + k * (ll)q[j].size());
		acu += a[i];
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}