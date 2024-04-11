#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

/* Fast Integer IO */
template<typename T> inline T read(T &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<typename T, typename... Args> inline void read(T &x, Args& ...args){
	read(x); read(args...);
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define MAXN 200005

int N, K;
bool in_cycle[MAXN];
vector <int> order, nxtv;
vector <int> con[MAXN], conv[MAXN];

lld t_diam[MAXN], t_far[MAXN];

bool vis[MAXN];
vector <int> stk, stkv;
bool find_cycle(int n, int from, int fromv)
{
	vis[n] = 1; stk.pb(n); stkv.pb(fromv);
	for (int i=sz(con[n]);i--;){
		int t = con[n][i], v = conv[n][i];
		if (t == from) continue;
		if (vis[t]){
			for (;;){
				int x = stk.back(); stk.pop_back();
				int l = stkv.back(); stkv.pop_back();
				in_cycle[x] = 1; order.pb(x); nxtv.pb(l);
				if (x == t) break;
			}
			nxtv.back() = v;
			return 1;
		}else{
			if (find_cycle(t, n, v)) return 1;
		}
	}
	stk.pop_back(); stkv.pop_back();
	return 0;
}

void dfs(int n, int p)
{
	lld mx2 = 0;
	for (int i=sz(con[n]);i--;){
		int t = con[n][i], v = conv[n][i];
		if (t == p || in_cycle[t]) continue;
		dfs(t, n);
		if (t_far[n] < t_far[t]+v)
			mx2 = t_far[n], t_far[n] = t_far[t]+v;
		else if (mx2 < t_far[t]+v)
			mx2 = t_far[t]+v;
	}
	t_diam[n] = t_far[n]+mx2;
}

lld sum[MAXN];
lld pre_diam[MAXN], pre_far[MAXN];
lld post_diam[MAXN], post_far[MAXN];

int main()
{
	read(N);
	for (int i=1;i<=N;i++){
		int a, b, c; read(a, b, c);
		con[a].pb(b); conv[a].pb(c);
		con[b].pb(a); conv[b].pb(c);
	}
	find_cycle(1, 0, 0);
	// for (int t: order) debug("%d ", t); debug("\n");
	// for (int t: nxtv) debug("%d ", t); debug("\n");
	for (int t: order) dfs(t, 0);
	lld base = 0, ans = 1e18;
	for (int i=1;i<=N;i++) base = max(base, t_diam[i]);

	K = sz(order);
	for (int i=1;i<=K;i++) sum[i] = sum[i-1]+nxtv[i-1];
	lld mx = -1e18;
	for (int i=0;i<K;i++){
		lld v = t_far[order[i]]+sum[i];
		pre_far[i] = max(i > 0 ? pre_far[i-1] : 0, v);
		if (i > 0) pre_diam[i] = max(pre_diam[i-1], v+mx);
		v = t_far[order[i]]-sum[i];
		mx = max(mx, v);
	}
	mx = -1e18;
	for (int i=K;i--;){
		lld v = t_far[order[i]]+sum[K]-sum[i];
		post_far[i] = max(post_far[i+1], v);
		if (i < K-1) post_diam[i] = max(post_diam[i+1], v+mx);
		v = t_far[order[i]]-(sum[K]-sum[i]);
		mx = max(mx, v);
	}

	// for (int i=0;i<K;i++) debug("%d: %lld %lld %lld %lld\n", i, pre_diam[i], pre_far[i], post_diam[i], post_far[i]);

	for (int i=0;i<K;i++){
		lld v = max({base, pre_diam[i], post_diam[i+1], pre_far[i]+post_far[i+1]});
		ans = min(ans, v);
	}
	write(ans); puts("");
}