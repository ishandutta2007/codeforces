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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 1003;
int n, k1, k2, k, a[MX], b[MX];
priority_queue<int> pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k1 >> k2;
	k = k1 + k2;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		pq.push(abs(a[i] - b[i]));
	}

	while (k--) {
		int x = pq.top();
		pq.pop();
		x--;
		pq.push(abs(x));
	}

	ll res = 0;
	while (pq.size()) {
		ll x = pq.top();
		pq.pop();
		res += x * x;
	}
	cout << res << endl;

	return 0;
}