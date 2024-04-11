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

const int MX = 200005;
int n, a[MX], b[MX];
set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn(i, n) st.insert(i + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st.erase(a[i]);
		if (!a[i])
			b[i] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (!a[i]) {
			if (st.count(i)) {
				a[i] = i;
				st.erase(i);
			}
		}

	for (int i = 1; i <= n; i++)
		if (!a[i]) {
			a[i] = *st.begin();
			st.erase(st.begin());
		}

	int aux = -1;
	for (int i = 1; i <= n; i++)
		if (b[i]) {
			int t = a[i];
			a[i] = aux;
			aux = t;
		}

	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) cout << aux << " ";
		else cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}