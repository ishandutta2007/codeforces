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

const int MX = 1005;
int n;
set<ii> st;

void go (int l, int r) {
	if (l > r) return;
	st.erase({l, r});
	
	for (int i = l; i <= r; i++) {
		bool f = l < i ? st.count({l, i - 1}) : 1;
		bool g = i < r ? st.count({i + 1, r}) : 1;
		
		if (f && g) {
			cout << l << " " << r << " " << i << endl;
			go(l, i - 1);
			go(i + 1, r);
			return;
		}
	}
}

void main_() {
	cin >> n;
	forn (i, n) {
		int a, b;
		cin >> a >> b;
		st.emplace(a, b);
	}
	
	go(1, n);
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