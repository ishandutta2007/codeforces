#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 1000000007;
int n, x, a[MX];
ll sum = 0, p;

ll pot (ll b, ll p) {
	ll res = 1;
	b %= mod;
	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}
	return res;
}

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < n; i++)
		pq.push(sum-a[i]);

	while (pq.size()) {
		int cn = 0;
		ll act = pq.top();
		p = act;
		if (p > sum) break;
		
		while (pq.size() && act == pq.top()) {
			cn++;
			pq.pop();
		}

		if (cn % x) break;

		cn /= x;
		while (cn--)
			pq.push(act+1);
	}

	cout << pot(x, min(p, sum)) << endl;

	return 0;
}