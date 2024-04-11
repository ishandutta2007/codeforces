// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 100005; 
int n, m;
vi a[MX], b[MX][1 << 5];

struct Node {
	unordered_map<int, int> sig;
	int cn;
	
	Node () : cn(0) {}
};
vector<Node> t;

void insert (const vi &a, int k) {
	int u = 0;
	for (int x : a) {
		if (!t[u].sig.count(x)) {
			t[u].sig[x] = t.size();
			t.emplace_back();
		}
		u = t[u].sig[x];
	}
	t[u].cn += k;
}

int query (const vi &a) {
	int u = 0;
	for (int x : a) {
		if (!t[u].sig.count(x)) {
			return 0;
		}
		u = t[u].sig[x];
	}
	return t[u].cn;
}

int count (int i) {
	int cn = 0;
		
	forn (mk, (1 << m)) {
		int p = query(b[i][mk]);
		if (__builtin_popcount(mk) & 1) cn -= p;
		else cn += p;
	}
	
	return cn;
}

void update (int i, int k) {
	forn (mk, (1 << m))
		insert(b[i][mk], k);
}

void main_() {
	t.emplace_back();
	
	cin >> n >> m;
	forn (i, n) {
		a[i].resize(m + 1);
		
		forn (j, m)
			cin >> a[i][j + 1];
		cin >> a[i][0];
		
		sort(a[i].begin() + 1, a[i].end());
	}
	sort(a, a + n);
	
	forn (i, n)
		forn (mk, (1 << m))
			forn (j, m)
				if (mk & (1 << j))
					b[i][mk].pb(a[i][j + 1]);
	
	ll res = 1e18;
	
	int j = -1;
	forn (i, n) {
		int k = count(i);
		
		if (j == -1 && k)
			j = i - 1;
		
		while (j > 0 && k) {
			update(j, -1);
			
			if (count(i)) {
				j--;
				continue;
			}
			
			update(j, 1);
			break;
		}
		
		if (k)
			res = min(res, 0ll + a[i][0] + a[j][0]);
		
		if (j == -1)
			update(i, 1);
	}
	
	if (res == 1e18) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		main_();
	
	return 0;
}