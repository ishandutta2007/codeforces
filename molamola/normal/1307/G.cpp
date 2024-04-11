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

namespace MCMF{
	const int MV = 300;
	const int ME = 30000;
	int st[MV], en[ME<<1], nxt[ME<<1], flow[ME<<1], cost[ME<<1], ce;
	const int INF = 1e9;
	void init() {
		memset(st, 0, sizeof st);
		ce = 1;
	}
	void addE(int s, int e, int c, int f = 1){
		++ce; nxt[ce] = st[s]; st[s] = ce; en[ce] = e; flow[ce] = f; cost[ce] = c;
		++ce; nxt[ce] = st[e]; st[e] = ce; en[ce] = s; flow[ce] = 0; cost[ce] = -c;
	}

	int inq[MV], pre[MV];
	int dis[MV];
	int spfa(int N, int ST, int EN){
		for(int i=1;i<=N;i++)inq[i] = 0, pre[i] = -1, dis[i] = INF;
		queue <int> que;
		inq[ST] = 1; que.push(ST); dis[ST] = 0;
		while(!que.empty()){
			int t = que.front(); que.pop();
			inq[t] = 0;
			for(int i=st[t];i;i=nxt[i])if(flow[i] > 0){
					if(dis[en[i]] > dis[t] + cost[i]){
						dis[en[i]] = dis[t] + cost[i];
						pre[en[i]] = i;
						if(inq[en[i]] == 0){
							que.push(en[i]);
							inq[en[i]] = 1;
						}
					}
				}
		}
		if(dis[EN] == INF) return INF;
		int t = EN;
		while(t != ST){
			int p = pre[t];
			flow[p]--;
			flow[p^1]++;
			t = en[p^1];
		}
		return dis[EN];
	}

	int Get(int N, int ST, int EN) {
		int ans = 0;
		while(1) {
			int t = spfa(N, ST, EN);
			if(t == INF) break;
			ans += t;
		}
		return ans;
	}
}

double ans[100010];

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	MCMF::init();
	rep(i, m) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		MCMF::addE(x, y, c, 1);
	}

	map <int, int> Mx;
	while(1) {
		int co = MCMF::spfa(n, 1, n);
		Mx[co]++;
		if(co == MCMF::INF) break;
	}

	vector <pii> Vx;
	for(pii e : Mx) Vx.pb(e);
	ans[0] = Vx[0].Fi;
	ll now = 0, ar = Vx[0].Se;
	for(int i=1;i<szz(Vx);i++) {
		ll nxt = (Vx[i].Fi - Vx[i-1].Fi) * ar;
		for(ll x=now+1;x<=now+nxt;x++) {
			if(x > 100000) break;
			ans[x] = ans[now] + (double)(x - now) / ar;
		}
		now += nxt;
		ar += Vx[i].Se;
	}
	for(ll x=now+1;x<=100000;x++) {
		ans[x] = ans[now] + (double)(x-now) / ar;
	}
	int q; scanf("%d", &q);
	rep(qq, q) {
		int x; scanf("%d", &x);
		printf("%.12f\n", ans[x]);
	}
}

int main() {
	int T = 1; //scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}