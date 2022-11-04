// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 250005;
int n, a[MX], f[MX], smn[MX], smx[MX];

void main_() {
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		f[a[i]] = i;
	}
	
	set<int> st;
	forr (i, 1, n) {
		auto it = st.upper_bound(f[i]);
		if (it != st.end()) smn[f[i]] = *it;
		else smn[f[i]] = n;
		st.insert(f[i]);
	}
	
	st.clear();
	for (int i = n; i >= 1; i--) {
		auto it = st.upper_bound(f[i]);
		if (it != st.end()) smx[f[i]] = *it;
		else smx[f[i]] = n;
		st.insert(f[i]);
	}
	
	int i = 0, res = 0;
	while (i < n - 1) {
		int x = smn[i];
		int y = smx[i];
		res++;
		
		if (x < y) {
			while (smn[i] < y)
				i = smn[i];
		} else {
			while (smx[i] < x)
				i = smx[i];
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}