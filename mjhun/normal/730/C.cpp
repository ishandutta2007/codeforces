#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(int i = a, qwer = n;i<qwer;i++)
#define inf 2e9
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 5005;
ii dp[N];
pair<ii,int> r[N];
vector<ii> s[N];
vector<vector<int> > g;
bool vis[N];
int d[N];
int q[N],ql,qr;
int h;

void bfs(int u){
	memset(vis,0,sizeof vis);
	memset(d,0,sizeof d);
	ql=0;qr=0;
	q[qr++]=u;
	vis[u] = 1;
	h = 0;
	while(!(ql==qr)) {
		int k = q[ql];
		ql++;
		fore(i,0,s[k].size())r[h++]=mp(ii(s[k][i].snd,s[k][i].fst),d[k]);
		fore(i,0,g[k].size()) {
			int v = g[k][i];
			if(!vis[v]) {
				vis[v] = 1;
				q[qr++]=v;
				d[v] = d[k]+1;
			}
		}
	}
	sort(r,r+h);
}

bool can(int u, int cc, int pp, int mid){
	int c = cc, p = pp;
	fore(i,0,h) {
		if(r[i].snd>mid)continue;
		if(c == 0 || r[i].fst.fst > p)
			break;
		int f = p/r[i].fst.fst;
		f = min(f,r[i].fst.snd);
		f = min(c,f);
		c -= f;
		p -= f*r[i].fst.fst;
	}
	return c==0;
}

int main() {
	int n,m,w,h;
	scanf("%d%d",&n,&m);
	g.resize(n);
	fore(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	scanf("%d",&w);
	fore(i,0,w) {
		int u,v,p;
		scanf("%d%d%d",&u,&v,&p);
		u--;
		s[u].pb(ii(v,p));
	}
	int q;
	scanf("%d",&q);
	fore(qq,0,q) {
		int u,cc,pp;
		scanf("%d%d%d",&u,&cc,&pp);
		u--;
		/*if(s[u].fst >= cc && s[u].snd * cc <= pp) {
			puts("0");
			continue;
		}*/
		bfs(u);
		int mn = 0, mx = n+5;
		while(mx - mn > 1) {
			int mid = (mn+mx)/2;
			if(can(u,cc,pp,mid-1))mx=mid;
			else mn=mid;
		}
		if(mx > n+1) {
			puts("-1");
			continue;
		}
		printf("%d\n",mn);
	}
	return 0;
}