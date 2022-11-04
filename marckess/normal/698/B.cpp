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
int n, a[MX], vis[MX], r = -1, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i) r = i;
	}

	if (r != -1) vis[r] = 2;

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			int u = i;
			stack<int> st;

			while (1) {
				vis[u] = 1;

				if (vis[a[u]] == 1) {
					if (r != -1) {
						a[u] = r;
					} else {
						a[u] = u;
						r = u;
					}
					res++;
					st.push(u);
					break;
				} else if (vis[a[u]] == 2) {
					st.push(u);
					break;
				} else {
					st.push(u);
					u = a[u];
				}
			}

			while (st.size()) {
				vis[st.top()] = 2;
				st.pop();
			}
		}

	cout << res << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}