#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll cost (int n, int k) {
	ll x = n / k;
	ll a = k - n % k;
	ll b = n % k;
	return x * x * a + (x + 1) * (x + 1) * b;
}

const int MX = 100005;
int n, k, a[MX], p[MX];
ll res;
priority_queue<ii, vii, greater<ii>> pq;

void solve () {
	cin >> n >> k;
	k -= n;
	
	forn (i, n) {
		cin >> a[i];
		res += cost(a[i], 1);
		p[i] = 1;
		if (p[i] < a[i]) {
			pq.emplace(cost(a[i], p[i] + 1) - cost(a[i], p[i]), i);
		}
	}
	
	while (k) {
		ll w = pq.top().fi;
		int i = pq.top().se;
		pq.pop();
		k--;
		res += w;
		p[i]++;
		if (p[i] < a[i]) {
			pq.emplace(cost(a[i], p[i] + 1) - cost(a[i], p[i]), i);
		}
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}