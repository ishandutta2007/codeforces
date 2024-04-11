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

const int MX = 111;
int n, p;
vi a;

void main_() {
	cin >> n >> p;
	a = vi(n);
	forn (i, n)
		cin >> a[i];
	reverse(all(a));
	
	set<int> st;
	forn (i, n)
		st.insert(a[i]);
	
	if (st.size() == p) {
		cout << 0 << endl;
		return;
	}
	
	int mn = 0;
	while (st.count(mn))
		mn++;
	
	int mx = p - 1;
	while (st.count(mx))
		mx--;
	
	if (mn >= a[0]) {
		cout << mx - a[0] << endl;
		return;
	}
	
	vi b = a;
	b.pb(0);
	
	b[0] = 0;
	for (int i = 1; i < b.size(); i++) {
		b[i]++;
		if (b[i] == p) {
			b[i] = 0;
		} else {
			break;
		}
	}
	
	for (int x : b)
		st.insert(x);
	
	mn = 0, mx = a[0];
	while (st.count(mn))
		mn++;
	
	while (st.count(mx))
		mx--;
	
	if (mn > a[0]) {
		cout << p - a[0] << endl;
		return;
	}
	
	cout << p - a[0] + mx << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}