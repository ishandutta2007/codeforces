#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
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
int n, a[MX], b[MX], acu[MX];
set<int> st;
vii res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a[i] >> b[i];
		acu[a[i]]++;
		acu[b[i]]++;
	}

	if (acu[n] != n-1 || !acu[n-1]) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 1; i <= n-2; i++)
		if (!acu[i])
			st.insert(i);

	for (int i = 1; i <= n-1; i++)
		if (acu[i]) {
			int ant = i;

			while (acu[i] > 1) {
				acu[i]--;

				if (i < *st.begin()){
					cout << "NO" << endl;
					return 0;
				}

				res.emplace_back(*st.begin(), ant);
				ant = *st.begin();
				st.erase(st.begin());
			}

			res.emplace_back(n, ant);
		}

	cout << "YES" << endl;
	for (auto r : res)
		cout << r.fi << " " << r.se << endl;

	return 0;
}