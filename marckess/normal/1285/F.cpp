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

const int MX = 100005;
int n, a[MX], cn[MX], m[MX], bs[MX];
ll res;
stack<int> st;
vi d[MX];
set<int> in;

int count (int n) {
	int res = 0;
	for (int y : d[n])
		res += m[y] * cn[y];
	return res;
}

int main() {
	ios_base::sync_with_stdio(); cin.tie(0);
	
	fill(m, m+MX, 1);
	for (int j = 1; j < MX; j++)
		d[j].pb(1);

	for (int i = 2; i < MX; i++) {
		for (int j = i; j < MX; j += i)
			d[j].pb(i);

		if (!bs[i]) {
			for (int j = i; j < MX; j += i) {
				bs[j] = 1;
				m[j] *= -1;
			}
	
			for (ll j = 1ll * i * i; j < MX; j += i * i)
				m[j] = 0;
		}
	}

	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		in.insert(a);
	}

	for (int x : in)
		for (int y : d[x])
			a[y] = 1;

	for (int i = MX - 1; i; i--)
		if (a[i]) {
			for (int y : d[i])
				cn[y]++;
			st.push(i);
		}

	for (auto it = in.end(); it != in.begin();) {
		it--;
		while (count(*it)) {
			int x = st.top();
			st.pop();
			
			if (__gcd(x, *it) == 1)
				res = max(res, 1ll * x * *it);
			
			for (int y : d[x])
				cn[y]--;
		}
	}

	cout << res << endl;

	return 0;
}