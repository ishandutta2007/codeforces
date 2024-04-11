
// Problem : D. The Strongest Build
// Contest : Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1574/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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

struct Node {
	map<int, Node*> nex;
}*t;

int n, c[11];
vi a[11];
int m;

void insert (Node *t, vi b) {
	for (int x : b) {
		if (!t->nex.count(x))
			t->nex[x] = new Node();
		t = t->nex[x];
	}
}

vi res, act;
int mx, acu;

void dfs (Node *t, int i) {
	if (i == n) {
		if (!t && acu > mx) {
			mx = acu;
			res = act;
		}
		return;
	}
	
	if (!t) {
		act[i] = c[i] - 1;
		acu += a[i][c[i] - 1];
		dfs(0, i + 1);
		acu -= a[i][c[i] - 1];
		return;
	}
	
	for (int j = c[i] - 1; j >= 0; j--) {
		if (t->nex.count(j)) {
			act[i] = j;
			acu += a[i][j];
			dfs(t->nex[j], i + 1);
			acu -= a[i][j];
		} else {
			act[i] = j;
			acu += a[i][j];
			dfs(0, i + 1);
			acu -= a[i][j];
			break;
		}
	}
}

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> c[i];
		a[i] = vi(c[i]);
		for (int &x : a[i])
			cin >> x;
	}
	
	t = new Node();
	
	cin >> m;
	while (m--) {
		vi b(n);
		for (int &x : b) {
			cin >> x;
			x--;
		}
		insert(t, b);
	}
	
	act = res = vi(n, 0);
	mx = acu = 0;
	dfs(t, 0);
	
	for (int x : res)
		cout << x + 1 << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}