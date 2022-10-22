#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=1e5+5;
int n,b[N],a[N],k,tot;
vector<int> G[N];
int main() {
	int T=read();
	while(T--) {
		n=read();
		fr(i,0,n+1) G[i].clear();
		k=0;
		fr(i,1,n) {
			b[i]=read();
			G[b[i]].push_back(i);
		}
		vector<int> q; int now;
		if(G[0].size()) q.push_back(0),now=0;
		else q.push_back(n+1),now=1;
		tot=0;
		while(1) {
			if(now==0) k+=q.size();
			int u=-1;
			for(auto x:q) if(!G[x].size()) a[tot++]=x;
			else u=x;
			if(~u) a[tot++]=u,q=G[u],now^=1;
			else break;
		}
		cout<<k-(!!G[0].size())<<'\n';
		fr(i,1,n) cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}