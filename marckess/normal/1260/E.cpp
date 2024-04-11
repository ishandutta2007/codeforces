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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = (1 << 18) + 5;
int n, a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	priority_queue<int, vi, greater<int>> pq;
	pq.push(a[n]);

	ll res = 0;
	for (int i = n - 1, j = n / 2; i > 0; j /= 2) {
		if (pq.top() == -1) break;
		res += max(0, pq.top());
		pq.pop();

		forn(kk, j)
			pq.push(a[i--]);
	}

	cout << res << endl;

	return 0;
}