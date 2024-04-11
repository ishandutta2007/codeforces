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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int m, a, b, vis[MX];
ll res = 0;
queue<int> q;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	memset(vis, -1, sizeof(vis));

	cin >> m >> a >> b;

	vis[0] = 0;
	for (int i = 1; i < min(MX, m+1); i++) {
		if (i - a >= 0 && vis[i - a] != -1) q.push(i), vis[i] = i;
		
		while (q.size()) {
			int u = q.front();
			q.pop();

			if (u + a <= i && vis[u + a] == -1) {
				q.push(u + a);
				vis[u + a] = i;
			}
			
			if (u - b >= 0 && vis[u - b] == -1) {
				q.push(u - b);
				vis[u - b] = i;
			}
		}
	}

	for (int i = 0; i < min(MX, m + 1); i++)
		if (vis[i] != -1)
			res += m - vis[i] + 1;

	ll g = __gcd(a, b);
	ll x = (MX / g) * g;
	if (x < MX) x += g;

	if (m < MX || x > m) {
		cout << res << endl;
		return 0;
	}

	ll cn = (m - x) / g + 1;
	res += cn * (m - x + 1) - g * cn * (cn - 1) / 2;
	cout << res << endl;

	return 0;
}