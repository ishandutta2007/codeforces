// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 100005;
int n, a, b;

void main_() {
	cin >> n >> a >> b;
	
	if (abs(a - b) > 1 || a + b + 2 > n) {
		cout << -1 << endl;
		return;
	}
	
	set<int> st;
	forn (i, n)
		st.insert(i + 1);
	
	vi v;
	int f = 0;
	if (b > a) {
		v.pb(*st.rbegin());
		f = 1;
	} else {
		v.pb(*st.begin());
		f = 0;
	}
	st.erase(v.back());
	
 	for (int i = 1; a || b; i++) {
		if (!f) {
			v.pb(*st.rbegin());
			a--;
			f = 1;
		} else {
			v.pb(*st.begin());
			b--;
			f = 0;
		}
		st.erase(v.back());
	}
	
	while (st.size()) {
		if (f) {
			v.pb(*st.rbegin());
		} else {
			v.pb(*st.begin());
		}
		st.erase(v.back());
	}
	
	for (int x : v)
		cout << x << " ";
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