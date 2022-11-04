#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, a;
	ll res = 0;
	priority_queue< ll, vector<ll>, greater<ll> > pq;

	cin >> n;
	if (n % 2 == 0)
		pq.push(0);
	while (n--) {
		cin >> a;
		pq.push(a);
	}

	while (pq.size() > 1) {
		ll nv = 0;
		for (int i = 0; i < 3; i++) {
			if (pq.size()) {
				nv += pq.top();
				pq.pop();
			}
		}
		res += nv;
		pq.push(nv);
	}

	cout << res << endl;

	return 0;
}