
// Problem : E. Divan and a Cottage
// Contest : Codeforces - Codeforces Round #757 (Div. 2)
// URL : https://codeforces.com/contest/1614/problem/E
// Memory Limit : 1024 MB
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

const int mod = 1000000001;
int n, off;
ordered_set st;

ordered_set::iterator find (int x) {
	int i = 0, j = int(st.size()) - 1;
	
	while (i < j) {
		int m = (i + j) / 2;
		
		if (st.find_by_order(m)->se + off - m >= x) j = m;
		else i = m + 1;
	}
	
	return st.find_by_order(j);
}

void update (int t, ordered_set::iterator it, int m) {
	int mn = it->fi;
	int mx = it->se;
	int x = t - off + m;
	
	st.erase(*it);
	
	if (mn < x) st.insert(ii(mn, x - 1));
	st.insert(ii(x, x));
	if (x < mx) st.insert(ii(x + 1, mx));
	
	m++;
}

void update (int t) {
	vector<ordered_set::iterator> v;
	
	auto it = find(t);
	auto jt = find(t + 1);
	
	int m = st.order_of_key(*it);
	int o = st.order_of_key(*jt);
	
	update(t, it, m);
	if (it != jt) update(t, jt, o);
	
}

int query (int x) {
 	int m = st.order_of_key(ii(x, 2e9 + 5)) - 1;
	return x + off - m;
}

void main_() {
	cin >> n;
	
	st.insert(ii(-2e9, 2e9));
	
	int last = 0;
	while (n--) {
		int t;
		cin >> t;
		
		update(t);
		off++;
		
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			
			last = query((x + last) % mod);
			cout << last << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}