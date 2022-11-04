#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
ll n, k, m;
deque<ii> a, x, y;
ll res;

void merge (deque<ii> &d) {
	deque<ii> r;

	while (d.size()) {
		if (r.empty() || r.back().fi != d.front().fi) r.emplace_back(d.front().fi, 0);
		
		r.back().se += d.front().se;
		res += r.back().se / k;
		r.back().se %= k;
		if (!r.back().se) r.pop_back();

		d.pop_front();
	}

	swap(r, d);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> m;

	forn (i, n) {
		int in;
		cin >> in;
		a.emplace_back(in, 1);
	}
	
	merge(a);
	res *= m;

	if (m == 1) {
		cout << n * m - res * k << endl;
		return 0;
	} 

	if (a.size() == 1) {
		res += a.front().se * m / k;
		cout << n * m - res * k << endl;
		return 0;
	}
	

	while (a.size() >= 2) {
		if (a.back().fi != a.front().fi) break;

		x.push_back(a.front());
		y.push_front(a.back());

		res += (a.back().se + a.front().se) / k * (m - 1);
		a.back().se += a.front().se;
		a.back().se %= k;
		a.pop_front();
		
		if (!a.back().se) a.pop_back();
	}

	if (a.size() == 1) {
		x.emplace_back(a[0].fi, a[0].se * m);
		x.insert(x.end(), y.begin(), y.end());
		merge(x);
	}

	cout << n * m - res * k << endl;	

	return 0;
}