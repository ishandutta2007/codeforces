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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, k;
ii a[MX];
ll ans = 0, sum = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i].se >> a[i].fi;

	sort(a, a+MX, greater<ii>());
	priority_queue<int, vi, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		ans = max(ans, (sum + a[i].se) * a[i].fi);

		sum += a[i].se;
		pq.push(a[i].se);

		if(pq.size() == k) {
			sum -= pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;

	return 0;
}