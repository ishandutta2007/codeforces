// 2021, After NOI 2021
#include <bits/stdc++.h>
#define rep(i, x, y) for(auto i = x; i < y; i++)
#define REP(i, x, y) for(auto i = x; i <= y; i++)
#define per(i, x, y) for(auto i = x - 1; i >= y; i--)
#define PER(i, x, y) for(auto i = x; i >= y; i--)
#define LLL __int128
#define int128 __int128
#define DBG(x) cerr << #x << " : " << x << endl
#define rg register
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned int uint;
typedef long long int64;
typedef long long LL;
typedef long long ll;
typedef unsigned long long uint64;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef long double LLF;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline void NO() { cout << "NO\n"; }
inline void YES() { cout << "YES\n"; }
inline void NEG() { cout << "-1\n"; }
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
template<typename T> inline void read(T &val) {
	val = 0; char c = getchar(); int f = 1;
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { val = (val << 3) + (val << 1) + (c ^ 48); c = getchar(); }
	val *= f;
}
template<typename T> void write_(T val) { if(!val) return; write_(val / 10); putchar(val % 10 | 48); }
template<typename T> inline void write(T val) {
	if(val == 0) putchar(48);
	else if(val < 0) { putchar('-'); write_(-val); }
	else write_(val);
}

//#define int long long

const int N = 1005;
int n, tot, ans, cent, siz[N], mxs[N];
vector<pair<int, bool>> G[N];
bool chs[N];

void get(int u, int fa) {
	siz[u] = 1;
	mxs[u] = 0;
	for(auto e : G[u]) {
		int v = e.first, w = e.second;
		if(v == fa || !w) continue;
		get(v, u);
		siz[u] += siz[v];
		chkmax(mxs[u], siz[v]);
	}
	chkmax(mxs[u], tot + 1 - siz[u]);
	if(mxs[u] < mxs[cent]) {
		cent = u;
	}
}

void dfs(int u, int fa) {
	siz[u] = 1;
	for(auto e : G[u]) {
		int v = e.first, w = e.second;
		if(v == fa || !w) continue;
		get(v, u);
		siz[u] += siz[v];
	}
}

vector<int> vert;

void ins(int u, int fa) {
	vert.pb(u);
	for(auto e : G[u]) {
		int v = e.first, w = e.second;
		if(v == fa || !w) continue;
		ins(v, u);
	}
}

signed main() {
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	// ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	read(n);
	rep(i, 1, n) {
		int u, v;
		read(u);
		read(v);
		G[u].pb({v, true});
		G[v].pb({u, true});
	}
	
	int cnt=1;
	
	printf("? %d ", n);
	REP(i, 1, n) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	
	scanf("%d", &ans);
	mxs[0] = INT_MAX;
	tot = n - 1;
	cent = 1;
	while(tot > 1) {
		int rt = cent;
		cent = 0;
		get(rt, 0);
		dfs(cent, 0);
		vector<pair<int, int>> tmp;
		tmp.clear();
		for(auto e : G[cent]) {
			int v = e.first, w = e.second;
			if(!w) continue;
			tmp.pb({siz[v], v});
		}
		sort(tmp.begin(), tmp.end());
		int rem = tot / 2;
		vert.clear();
		// DBG(cent);
		memset(chs, false, sizeof(chs));
		for(int i = tmp.size() - 1; ~i; i--) {
			if(rem >= tmp[i].first) {
				rem -= tmp[i].first;
				ins(tmp[i].second, cent);
				chs[tmp[i].second] = true;
			}
		}
		vert.pb(cent);
		
		++cnt;
		if(cnt>12)break;
		
		printf("? %llu ", vert.size());
		for(int x : vert) printf("%d ", x);
		printf("\n");
		fflush(stdout);

		int res;
		scanf("%d", &res);
		tot = 0;
		if(res == ans) {
			for(auto &e : G[cent]) {
				int v = e.first, w = e.second;
				if(!w) continue;
				if(!chs[v]) e.second = false;
				else tot += siz[v];
			}
		} else {
			for(auto &e : G[cent]) {
				int v = e.first, w = e.second;
				if(!w) continue;
				if(chs[v]) e.second = false;
				else tot += siz[v];
			}
		}
	}
	printf("! %d ", cent);
	for(auto e : G[cent]) {
		if(e.second) {
			printf("%d\n", e.first);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}