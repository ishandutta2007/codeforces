#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=2e5+9;

struct edge {int to,nxt,w;} e[N*2]; int hd[N],tot;
void add(int u,int v,int w) {e[++tot]=(edge){v,hd[u],w};hd[u]=tot;}

struct bucket {
	queue<int>q[N];
	int pos,mx;
	bucket() {pos=mx=0;}
	void init() {pos=mx=0;}
	void insert(int x,int y) {q[y].push(x); mx=max(mx,y);}
	bool empty() {
		while(pos<=mx&&q[pos].empty()) pos++;
		if(pos>mx) return 1;
		else return 0;
	}
	int front() {
		while(q[pos].empty()) {
			pos++;
			if(pos>mx) throw "TRUMP";
		}
		return q[pos].front();
	}
	void pop() {
		if(q[pos].empty()) throw "TRUMP";
		q[pos].pop();
	}
};

int n,m,q,d[N],g[N];
bool vst[N];
bucket b;

void dij() {
	priority_queue<pii>q; q.push(make_pair(0,1));
	rep(i,1,n) d[i]=0x3f3f3f3f3f3f3f3f; d[1]=0;
	while(!q.empty()) {
		int u=q.top().second; q.pop();
		if(vst[u]) continue; vst[u]=1;
		for(int i=hd[u],v;i;i=e[i].nxt) {
			if(d[v=e[i].to]>d[u]+e[i].w)
				d[v]=d[u]+e[i].w, q.push(make_pair(-d[v],v));
		}
	}
}
void dji(int cnt) {
	rep(i,2,n) g[i]=0x3f3f3f3f3f3f3f3f; g[1]=0;
	rep(i,1,n) vst[i]=0;
	b.init(); b.insert(1,0);
	while(!b.empty()) {
		int u=b.front(); b.pop();
		if(vst[u]) continue; vst[u]=1;
		for(int i=hd[u],v;i;i=e[i].nxt) {
			v=e[i].to; int w=d[u]-d[v]+e[i].w;
			if(g[v]>g[u]+w) {
				g[v]=g[u]+w;
				if(g[v]<=min(cnt,n-1)) b.insert(v,g[v]);
			}
		}
	}
}

signed main() {
	n=read(), m=read(), q=read();
	rep(i,1,m) {
		int u=read(), v=read(), w=read();
		add(u,v,w);
	}
	dij();
	rep(i,1,q) {
		int opt=read();
		if(opt==2) {
			int c=read();
			rep(j,1,c) {
				int id=read();
				e[id].w++;
			}
			dji(c);
			rep(i,1,n) d[i]+=g[i];
			rep(i,1,n) d[i]=min(d[i],0x3f3f3f3f3f3f3f3f);
		} else {
			int v=read();
			printf("%lld\n",d[v]==0x3f3f3f3f3f3f3f3f?-1ll:d[v]);
		}
	}
	return 0;
}//