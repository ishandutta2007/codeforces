#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int N=1e5+9;
typedef pair<int,int> pii;

inline long long read() {
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-48; c=getchar();}
	return x*f;
}

int n,m,s1,s2,t,k,l[N],r[N],w[N],u[N],v[N],d1[N],d2[N];
vector<pii>e[N];
bool vst[N];

void dijkstra(int *d,int s) {
	priority_queue<pii>q; q.push(pii(0,s));
	rep(i,1,n) d[i]=1000000000000000000; d[s]=0;
	while(!q.empty()) {
		pii pp=q.top(); q.pop(); int u=pp.second;
		if(vst[u]) continue;
		for(auto ed:e[u]) if(d[ed.first]>d[u]+ed.second)
			d[ed.first]=d[u]+ed.second, q.push(pii(-d[ed.first],ed.first));
	}
}

void solve() {
	rep(i,1,m) w[i]=r[i];
	rep(i,1,n) e[i].clear();
	rep(i,1,m) e[u[i]].push_back(pii(v[i],w[i]));
	dijkstra(d1,s1), dijkstra(d2,s2);
	while(1) {
		bool change=0;
		rep(i,1,m) {
			if(w[i]!=l[i]&&(d1[u[i]]<=d2[u[i]]||d1[u[i]]+w[i]==d1[v[i]]
					&&d2[u[i]]+w[i]>d2[v[i]])) w[i]=l[i], change=1; 
		}
		rep(i,1,n) e[i].clear();
		rep(i,1,m) e[u[i]].push_back(pii(v[i],w[i]));
		dijkstra(d1,s1), dijkstra(d2,s2);
		if(!change) break;
	}
	if(d1[t]<d2[t]) puts("WIN");
	else if(d1[t]==d2[t]) puts("DRAW");
	else puts("LOSE");
	if(d1[t]<=d2[t]) {
		rep(i,m-k+1,m) printf("%lld ",w[i]);
		puts("");
	}
}


signed main() {
	n=read(), m=read(), k=read(), s1=read(), s2=read(), t=read();
	rep(i,1,m) u[i]=read(), v[i]=read(), l[i]=r[i]=read();
	rep(i,m+1,m+k) u[i]=read(), v[i]=read(), l[i]=read(), r[i]=read();
	m+=k;
	solve();
	return 0;
}