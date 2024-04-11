#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 100000000000000005
#define MOD 1000000007
#define MAXN 12
#define MAXC 200002
#define MAXM 100002

int n;
int c[MAXC];
int a[MAXN][MAXC];
int m;
int b[MAXM][MAXN];
int mp[MAXN], omp[MAXN], imp[MAXN];

struct node {
	unordered_map<int, node*> child;
	node *p;
	bool all;
} *illegal;

int cnt;
void dfs(int i, int j, int rem) {
	if (i >= n || j >= c[i] || rem < 0) return;
	cnt++;
	if (cnt > m) return;
	dfs(i, j + 1, rem + a[i][j] - a[i][j + 1]);
	REP (j, i + 1, n + 1) {
		if (rem - a[j][1] < 0) break;
		if (a[j][1] != INF) {
			dfs(j, 1, rem - a[j][1]);
		}
	}
}

bool isPos(int x) {
	cnt = 0;
	dfs(0, 0, x);
	return cnt > m;
}

vi v;
int ans;
vi vans;
void dfs2(int i, int j, int rem, int sm, node* cnode) {
	if (i >= n) {
		if (cnode != nullptr) return;
		if (mnto(ans, sm)) {
			vans = v;
		}
		return;
	}
	if (j >= c[i] || rem < 0) return;
	int o = v[i];
	if (cnode == nullptr || cnode -> child[j] == nullptr || 
			!cnode -> child[j] -> all) {
		v[i] = j;
		if (mnto(ans, sm)) {
			vans = v;
		}
		v[i] = o;
	}
	cnt++;
	// if (cnt > m) return;
	v[i] = j + 1;
	if (a[i][j + 1] != INF) {
		dfs2(i, j + 1, rem + a[i][j] - a[i][j + 1],
			   	sm - a[i][j] + a[i][j + 1], cnode);
	}
	v[i] = j;
	node *nnode;
	if (cnode == nullptr || cnode -> child.find(j) == cnode -> child.end()) {
		nnode = nullptr;
	} else {
		nnode = cnode -> child[j];
	}
	REP (j, i + 1, n + 1) {
		if (rem - a[j][1] < 0) break;
		v[j] = 1;
		if (a[j][1] != INF) {
			dfs2(j, 1, rem - a[j][1], sm + a[j][1], nnode);
		}
		v[j] = 0;
		if (nnode == nullptr || nnode -> child.find(0) == nnode -> child.end()) {
			nnode = nullptr;
		} else {
			nnode = nnode -> child[0];
		}
	}
	v[i] = o;
}

void dfs3(int i, int j, int rem, int sm, node* cnode) {
	if (i >= n) {
		if (cnode != nullptr) return;
		if (rem == 0) {
			vans = v;
		}
		return;
	}
	if (j >= c[i] || rem < 0) return;
	int o = v[i];
	if (cnode == nullptr || cnode -> child[j] == nullptr || 
			!cnode -> child[j] -> all) {
		v[i] = j;
		if (rem == 0) {
			vans = v;
		}
		v[i] = o;
	}
	if (!vans.empty()) return;
	cnt++;
	// if (cnt > m) return;
	v[i] = j + 1;
	if (a[i][j + 1] != INF) {
		dfs3(i, j + 1, rem + a[i][j] - a[i][j + 1],
			   	sm - a[i][j] + a[i][j + 1], cnode);
		if (!vans.empty()) return;
	}
	v[i] = j;
	node *nnode;
	if (cnode == nullptr || cnode -> child.find(j) == cnode -> child.end()) {
		nnode = nullptr;
	} else {
		nnode = cnode -> child[j];
	}
	REP (j, i + 1, n + 1) {
		if (rem - a[j][1] < 0) break;
		v[j] = 1;
		if (a[j][1] != INF) {
			dfs3(j, 1, rem - a[j][1], sm + a[j][1], nnode);
		}
		if (!vans.empty()) return;
		v[j] = 0;
		if (nnode == nullptr || nnode -> child.find(0) == nnode -> child.end()) {
			nnode = nullptr;
		} else {
			nnode = nnode -> child[0];
		}
	}
	v[i] = o;
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &c[i]);
		REP (j, 0, c[i]) {
			scanf("%d", &a[i][j]);
		}
		REP (j, 0, c[i]) {
			a[i][j] = a[i][c[i] - 1] - a[i][j];
		}
		reverse(a[i], a[i] + c[i]);
		a[i][c[i]] = INF;
		c[i]++;
	}
	scanf("%d", &m);
	illegal = new node();
	REP (i, 0, m) {
		REP (j, 0, n) {
			scanf("%d", &b[i][j]);
			b[i][j] = c[j] - b[i][j] - 1;
		}
	}
	REP (i, 0, n) {
		mp[i] = i;
	}
	sort(mp, mp + n, [&] (int l, int r) {
			return a[l][1] < a[r][1];
			});
	REP (i, 0, n) {
		imp[mp[i]] = i;
	}
	REP (i, 0, n) {
		omp[i] = imp[i];
	}
	REP (i, 0, n) {
		swap(a[i], a[mp[i]]);
		swap(c[i], c[mp[i]]);
		REP (j, 0, m) {
			swap(b[j][i], b[j][mp[i]]);
		}
		int tmp = mp[i];
		swap(mp[i], mp[imp[i]]);
		swap(imp[i], imp[tmp]);
	}
	REP (i, 0, m) {
		node* cur = illegal;
		REP (j, 0, n) {
			if (cur -> child.find(b[i][j]) == cur -> child.end()) {
				cur -> child[b[i][j]] = new node();
				cur -> child[b[i][j]] -> p = cur;
			}
			cur = cur -> child[b[i][j]];
		}
		RREP (j, n - 1, -1) {
			cur -> all = 1;
			if (j < 0 || b[i][j] != 0) break;
			cur = cur -> p;
		}
	}
	int lo = 0, hi = INF, mid;
	while (lo < hi) {
		mid = lo + hi >> 1;
		if (isPos(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	v.resize(n + 5, 0);
	ans = INF;
	cnt = 0;
	dfs2(0, 0, hi - 1, 0, illegal);
	debug("%d\n", cnt);
	if (vans.size() == 0) {
		dfs3(0, 0, hi, 0, illegal);
	}
	REP (i, 0, n) {
		printf("%d ", c[omp[i]] - vans[omp[i]] - 1);
	}
	printf("\n");
	return 0;
}