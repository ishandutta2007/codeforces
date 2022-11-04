#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 1e9+7;
int n, k, q[MX], dp[MX];
ll a[MX], izq[MX], der[MX];
set<int> st;

void obtIzqDer () {
	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		if (a[i] == a[j]) return i < j;
		return a[i] > a[j];
	});

	int i = 0, j = 0;
	st.insert(-1);
	while (i < n) {
		while (j < n && a[q[i]] < a[q[j]]) {
			st.insert(q[j]);
			j++;
		}

		auto it = st.upper_bound(q[i]);
		it--;
		izq[q[i]] = *it + 1;
		i++;
	}

	st.clear();
	st.insert(n);
	i = 0, j = 0;

	while (i < n) {
		while (j < n && a[q[i]] <= a[q[j]]) {
			st.insert(q[j]);
			j++;
		}

		auto it = st.upper_bound(q[i]);
		der[q[i]] = *it - 1;
		i++;
	}
}

ll comb (int a, int b, int c) {
	return (dp[c-a+1] - dp[b-a] - dp[c-b]) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = k; i <= n; i++) dp[i] = (dp[i-k+1] + i-k+1) % mod;
	obtIzqDer();

	ll res = 0;

	for (int i = 0; i < n; i++) {
		res += a[i] * comb(izq[i], i, der[i]) % mod;
		res %= mod;
	}

	cout << MOD(res, mod) << endl;

	return 0;
}