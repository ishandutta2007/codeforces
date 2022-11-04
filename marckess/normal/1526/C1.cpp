#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

struct ST {
	ll st[4 * MX], lz[4 * MX];
	
	void init () {
		memset(st, 0, sizeof(st));
		memset(lz, 0, sizeof(lz));
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		st[pos] += lz[pos];
		lz[pos] = 0;
	}
	
	void update (int i, int j, int pos, int a, int b, ll k) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = k;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
		
		st[pos] = min(st[pos * 2], st[pos * 2 + 1]);
	}
}st;

int n, a[MX];

void solve () {
	st.init();
	
	vii v;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0)
			v.emplace_back(a[i], i);
	}
	
	sort(all(v), greater<ii>());
	
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >= 0) {
			st.update(1, n, 1, i, n, a[i]);
			res++;
		}
	
	for (ii &p : v) {
		st.update(1, n, 1, p.se, n, p.fi);
		
		if (st.st[1] < 0) {
			st.update(1, n, 1, p.se, n, -p.fi);
		} else {
			res++;
		}
	}
	
	cout << res << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
 
	return 0;
}