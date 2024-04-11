#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int Trie[600060][26], tz;
char In[1010];
int n, m;
ll K;
const ll INF = 2e18;
vector <pii> sv[600060];
vector <pii> ord;
int nxt[1010];
ll dp[1010][1010], sdp[1010][1010];

inline void add(ll &a, ll b) {
	a += b;
	if(a > INF) a = INF;
}

ll Get() {
	memset(dp, 0, sizeof dp);
	memset(sdp, 0, sizeof sdp);
	dp[0][0] = 1;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			int k = nxt[j+1];
			add(sdp[i+1][k], dp[i][j]);
		}
		for(int j=1;j<=n;j++) {
			dp[i+1][j] = dp[i+1][j-1];
			add(dp[i+1][j], sdp[i+1][j]);
		}
	}
	return dp[m][n];
}

void dfs(int t) {
	for(pii e : sv[t]) ord.pb(e);
	rep(j, 26) if(Trie[t][j]) {
		dfs(Trie[t][j]);
	}
}

int main() {
	scanf("%d%d%lld", &n, &m, &K);
	scanf("%s", In + 1);
	for(int i=1;i<=n;i++) {
		int now = 0;
		for(int j=i;j<=n;j++) {
			int c = In[j] - 'a';
			if(!Trie[now][c]) Trie[now][c] = ++tz;
			now = Trie[now][c];
			sv[now].pb(pii(i, j));
		}
	}
	dfs(0);
	int low = 0, high = szz(ord) - 1;
	pii res = pii(-1, -1);
	while(low <= high) {
		int mid = (low + high) >> 1;
		for(int i=1;i<=n;i++) nxt[i] = i;
		for(int i=0;i<mid;i++) {
			int l, r; tie(l, r) = ord[i];
			nxt[l] = max(nxt[l], r + 1);
		}
		ll v = Get();
		if(v >= K) {
			res = ord[mid];
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	for(int i=res.Fi;i<=res.Se;i++) printf("%c", In[i]);
	puts("");
	return 0;
}