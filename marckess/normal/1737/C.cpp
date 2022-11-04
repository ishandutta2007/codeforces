#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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
	int n, r1, c1, r2, c2, r3, c3, x, y;
	
	cin >> n;
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	cin >> r3 >> c3;
	cin >> x >> y;
	
	set<ii> st;
	st.insert({r1, c1});
	st.insert({r2, c2});
	st.insert({r3, c3});
		
	if (st.count({1, 1}) && st.count({1, 2}) && st.count({2, 1})) {
		if (x == 1 || y == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return;
	}
	
	if (st.count({1, n}) && st.count({2, n}) && st.count({1, n - 1})) {
		if (x == 1 || y == n) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return;
	}
	
	if (st.count({n, 1}) && st.count({n - 1, 1}) && st.count({n, 2})) {
		if (x == n || y == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return;
	}
	
	if (st.count({n, n}) && st.count({n - 1, n}) && st.count({n, n - 1})) {
		if (x == n || y == n) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return;
	}
	
	vi cn(2);
	cn[r1 % 2]++;
	cn[r2 % 2]++;
	cn[r3 % 2]++;
	
	if (x % 2 == (max_element(all(cn)) - cn.begin())) {
		cout << "YES" << endl;
		return;
	}
	
	cn = vi(2);
	cn[c1 % 2]++;
	cn[c2 % 2]++;
	cn[c3 % 2]++;
	
	if (y % 2 == (max_element(all(cn)) - cn.begin())) {
		cout << "YES" << endl;
		return;
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}