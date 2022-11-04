
// Problem : B. Special Permutation
// Contest : Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1612/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void main_() {
	int n, a, b;
	cin >> n >> a >> b;
	
	set<int> st;
	for (int i = 1; i <= n; i++)
		st.insert(i);
	
	vi res(n);
	res[0] = a;
	res[n / 2] = b;
	
	st.erase(a);
	st.erase(b);
	
	for (int i = n / 2 + 1; st.size() && *st.begin() < a; i++) {
		if (i >= n) {
			cout << -1 << endl;
			return;
		}
		
		res[i] = *st.begin();
		st.erase(st.begin());
	}
	
	for (int i = 1; st.size() && *st.rbegin() > b; i++) {
		if (i >= n / 2) {
			cout << -1 << endl;
			return;
		}
		
		res[i] = *st.rbegin();
		st.erase(*st.rbegin());
	}
	
	forn (i, n)
		if (!res[i]) {
			res[i] = *st.begin();
			st.erase(st.begin());
		}
	
	if (*min_element(res.begin(), res.begin() + n / 2) != a) {
		cout << -1 << endl;
		return;
	}
	if (*max_element(res.begin() + n / 2, res.end()) != b) {
		cout << -1 << endl;
		return;
	}
	
	for (int x : res) cout << x << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}