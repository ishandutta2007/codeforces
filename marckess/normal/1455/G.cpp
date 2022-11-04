#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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
const ll inf = 1e18;
ll st[4 * MX], lz[4 * MX];

void sum (ll &a, ll b) {
	a += b;
	if (a > inf)
		a = inf;
}

void push (int i, int j, int pos) {
	if (i < j) {
		sum(lz[pos * 2], lz[pos]);
		sum(lz[pos * 2 + 1], lz[pos]);
	}
	
	sum(st[pos], lz[pos]);
	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, ll k) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		lz[pos] = k;
		push (i, j, pos);
		return;
	}
	
	int m = (i + j) / 2;
	update(i, m, pos * 2, a, b, k);
	update(m + 1, j, pos * 2 + 1, a, b, k);
	st[pos] = min(st[pos * 2], st[pos * 2 + 1]);
}

ll query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return inf;
	if (a <= i && j <= b) return st[pos];
	
	int m = (i + j) / 2;
	return min(
		query(i, m, pos * 2, a, b),
		query(m + 1, j, pos * 2 + 1, a, b)
	);
}

string op[MX];
int n, s, y[MX], v[MX];
ll dp[MX];
stack<int> si, vl, ex, pos[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	
	for (int i = 1; i <= n; i++) {
		cin >> op[i];
		
		if (op[i] != "end") {
			cin >> y[i];
			
			if (op[i] == "set")
				cin >> v[i];
		}
	}
	
	n++;
	op[0] = "set";
	
	for (int i = n - 1; i >= 0; i--) {
		if (op[i] == "end") {
			si.push(i);
			update(1, n, 1, i, i, inf);
		} else {
			if (y[i] == s) {
				dp[i] = inf;
			} else if (pos[y[i]].size()) {
				if (i + 1 <= pos[y[i]].top() - 1)
					dp[i] = query(1, n, 1, i + 1, pos[y[i]].top() - 1);
				else
					dp[i] = inf;
				
				dp[i] = min(
					dp[i], 
					query(1, n, 1, pos[y[i]].top(), pos[y[i]].top()) - inf / 2
				);
			} else {
				dp[i] = query(1, n, 1, i + 1, n);
			}
			
			if (i) update(1, n, 1, i, i, dp[i]);
			update(1, n, 1, i + 1, n, v[i]);
			
			if (op[i] == "if") {
				while (ex.size() && ex.top() < si.top()) {
					pos[y[ex.top()]].pop();
					ex.pop();
				}
				
				while (vl.size() && vl.top() < si.top()) {
					update(1, n, 1, vl.top() + 1, n, -v[vl.top()]);
					vl.pop();
				}
				
				update(1, n, 1, i + 1, si.top(), inf);
				update(1, n, 1, i, i, inf / 2);
				si.pop();
				
				ex.push(i);
				pos[y[i]].push(i);
			} else {
				vl.push(i);
			}
		}
	}
	
	cout << dp[0] << endl;
	
	return 0;
}