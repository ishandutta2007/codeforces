#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, a[MX], b[MX], cn = 0, res = 0;
multiset<int> st;
set<ii> pii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cn += !a[i];
		st.insert(a[i]);
	}

	res = max(res, cn);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && (a[i] || a[j])) {
				ii x(a[i], a[j]);
				if (pii.count(x)) continue;
				pii.insert(x);

				int p = 2;

				b[0] = a[i], b[1] = a[j];
				st.erase(st.find(b[0]));
				st.erase(st.find(b[1]));

				while (1) {
					b[p] = b[p-1] + b[p-2];
					auto it = st.find(b[p]);
					if (it == st.end()) break;
					st.erase(it);
					p++;
				}

				res = max(res, p);

				for (int i = 0; i < p; i++)
					st.insert(b[i]);
			}

	cout << res << endl;

	return 0;
}