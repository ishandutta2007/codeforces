#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9;
typedef pair<int,int> pii;
typedef vector<int> vi;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,deg[N],ans,f[N];
vector<int>e[N];

void topo() {
	queue<int>q;
	per(i,n,1) if(!deg[i]) q.push(-i), f[i]=1;
	while(!q.empty()) {
		int u=-q.front(); q.pop();
		for(int v:e[u]) {
			f[v]=max(f[v],f[u]+(u>v));
			if(!(--deg[v])) q.push(-v);
		}
	}
}

signed main() {
	T=read();
	while(T--) {
		n=read(), ans=0;
		rep(i,1,n) e[i].clear(), deg[i]=0, f[i]=0;
		rep(u,1,n) {
			deg[u]=read();
			rep(i,1,deg[u]) {
				int v=read();
				e[v].push_back(u);
			}
		}
		topo();
		bool flag=0;
		rep(i,1,n) if(deg[i]) flag=1;
		rep(i,1,n) ans=max(ans,f[i]);
		if(flag==1) puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}