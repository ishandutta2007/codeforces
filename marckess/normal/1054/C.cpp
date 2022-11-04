#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, l[MX], r[MX], res[MX];
stack<int> st;

bool check () {
	for (int i = 0; i < n; i++)
		if (!res[i]) {
			if (l[i] < 0 || r[i] < 0) return 0;
			if (l[i] == 0 && r[i] == 0) st.push(i);
		}
	return st.size();
}

void dec (int i, int k) {
	res[i] = k;
	m--;

	for (int j = i+1; j < n; j++)
		if (!res[j])
			l[j]--;

	for (int j = i-1; j >= 0; j--)
		if (!res[j])
			r[j]--;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	m = n;
	for (int i = 0; i < n; i++) cin >> l[i];
	for (int i = 0; i < n; i++) cin >> r[i];

	for (int i = n; i > 0 && m; i--) {
		if (!check()) {
			cout << "NO" << endl;
			return 0;
		}
		while (st.size()) {
			dec(st.top(), i);
			st.pop();
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}