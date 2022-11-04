#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, a[MX], b[MX], mx = 0, ex[MX], val[MX];
set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];

	forn (i, n) {
		if (!val[i]) st.insert(i);

		if (i + 1 < n && a[i] != a[i + 1]) {
			b[i + 1] = a[i];
			ex[a[i]] = 1;
			val[i + 1] = 1;
		}

		while (mx < a[i]) {
			if (ex[mx]) mx++;
			else {
				b[*st.begin()] = mx;
				st.erase(st.begin());
				mx++;
			}
		}
	}

	forn (i, n) {
		if (b[i] == a[i]) b[i] = 1e6;
		cout << b[i] << " ";
	}
	cout << endl;

	return 0;
}