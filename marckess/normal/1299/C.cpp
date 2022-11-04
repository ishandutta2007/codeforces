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

const int MX = 1000005;
int n;
ll a[MX], s[MX];
stack<ii> st;
ld res[MX];

ld f (int i, int j) {
	return ld(1) * (s[j] - s[i-1]) / (j - i + 1);
}

bool leq (ii a, ii b) {
	return (s[a.se] - s[a.fi - 1]) * (b.se - b.fi + 1) <= (s[b.se] - s[b.fi - 1]) * (a.se - a.fi + 1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	for (int i = 1; i <= n; i++) {
		st.emplace(i, i);
		
		while (st.size() >= 2) {
			ii a = st.top(); st.pop();
			ii b = st.top();
			
			if (leq(a, b)) {
				st.pop();
				st.emplace(b.fi, a.se);
			} else {
				st.push(a);
				break;
			}
		}
	}

	while (st.size()) {
		ii a = st.top();
		st.pop();

		for (int i = a.fi; i <= a.se; i++)
			res[i] = f(a.fi, a.se);
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;

	return 0;
}