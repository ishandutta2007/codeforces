//int!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
typedef long long ll;
#define M 1000000007

const int maxn = 100100;
int n, m, u, v;
ll w;
ll x[maxn];
bool vis[maxn], ins[maxn];
vector<pair<int, ll> > g[maxn];
vector<ll> cir, val;

void dfs(int t, int fa, ll s){
	x[t] = s;
	val.pb(x[t]);
	vis[t] = 1;
	ins[t] = 1;
	for(auto e : g[t]){
		int v = e.fi; ll w = e.se;
		if(v == fa) continue;
		if(ins[v]){
			cir.pb(x[t] ^ x[v] ^ w);
		}else{
			if(!vis[v]) dfs(v, t, s ^ w);
		}
	}
	ins[t] = 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%lld", &u, &v, &w);
		g[u].pb(mkp(v, w));
		g[v].pb(mkp(u, w));
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			cir.clear();
			val.clear();
			dfs(i, 0, 0);

			//sort(all(cir));
			//reverse(all(cir));
			int cnt = 0;
			for(int i = 0, j = 0; i < 60; ++i){
				ll val = 0; int p = 0;
				for(int k = j; k < cir.size(); ++k)
					if((cir[k] >> i) & 1) val = cir[k], p = k;
				if(!val) continue;
				swap(cir[j], cir[p]);
				for(int k = j + 1; k < cir.size(); ++k)
					if((cir[k] >> i) & 1) cir[k] ^= val;
				j++;
				cnt++;
			}
			
			for(int i = 0; i < 60; ++i){
				bool flag = 0;
				for(int j = 0; j < cnt; ++j)
					if((cir[j] >> i) & 1) flag = 1;
				int cnt0 = 0, cnt1 = 0;
				for(auto v : val)
					if((v >> i) & 1) cnt1++; else cnt0++;
				int base = (1LL << i) % M;
				if(flag){
					int bb = (1LL << (cnt - 1)) % M, tot = cnt1 + cnt0;
					ans = (ans + (ll)base * bb % M * ((ll)tot * (tot - 1) / 2 % M) % M) % M;
				}else{
					int bb = (1LL << cnt) % M;
					ans = (ans + (ll)base * bb % M * cnt1 % M * cnt0 % M) % M;
				}
			}
		}
	printf("%d\n", ans);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/