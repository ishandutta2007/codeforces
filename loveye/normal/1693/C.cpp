#include<cstdio>
#include<set>
#include<queue>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5,M=2e5+5;
int n,m;
vector<int> iG[N];
int d[N],f[N];
struct Node {
	int d,id;
	bool operator < (const Node &o) const {
		return d>o.d;
	}
};
priority_queue<Node> pq;
int main() {
	n=read(); m=read();
	for(int i=1,u,v;i<=m;++i) {
		u=read(),v=read();
		++f[u];
		iG[v].push_back(u);
	}
	fr(i,1,n) d[i]=m*2;
	pq.push(Node{d[n]=0,n});
	while(!pq.empty()) {
		Node now=pq.top(); pq.pop();
		int u=now.id;
		if(d[u]^now.d) continue;
		for(auto v:iG[u]) {
			--f[v];
			if(d[v]>d[u]+1+f[v])
				pq.push(Node{d[v]=d[u]+1+f[v],v});
		}
	}
	//fr(i,1,n) cout<<d[i]<<endl;
	printf("%d\n",d[1]);
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}