
// Problem : E2. Array Optimization by Deque
// Contest : Codeforces - Codeforces Round #744 (Div. 3)
// URL : https://codeforces.com/contest/1579/problem/E2
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 200005;
int n, a[MX];
ordered_set st;

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	ll res = 0;
	st.clear();
	
	forn (i, n) {
		st.insert({a[i], i});
		
		int x = st.order_of_key({a[i], -1});
		int y = st.size() - st.order_of_key({a[i] + 1, -1});
		res += min(x, y);
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