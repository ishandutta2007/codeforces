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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 200005;
int n, p[MX], f[MX], ft[MX];
ll res;

ordered_set st;

int count (int i, int j) {
	return (int)st.order_of_key(j + 1) - (int)st.order_of_key(i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		f[p[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		int izq = st.order_of_key(f[i]);
		int der = i - 1 - izq;
		res += der;
		res -= min(izq, der);

		if (i > 1) {
			if (izq < der) {
				int j = *st.find_by_order((i - 2) / 2);
				res += j - f[i] - count(f[i], j);
			}
			if (der < izq) {
				int j = *st.find_by_order((i - 1) / 2);
				res += f[i] - j - count(j, f[i]);
			}
		}

		st.insert(f[i]);		
		cout << res << " ";
	}
	cout << endl;

	return 0;
}