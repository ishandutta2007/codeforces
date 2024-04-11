#include<cstdio>
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

const int N=1e5+5;
int n,a[N];
vector<int> G[N];
void dfs(int u,int fa,int job) {
	int du=0;
	for(auto v:G[u]) if(v!=fa) {
		dfs(v,u,job^1);
		++du;
	}
	if(u==1) a[u]=1+(du-1);
	else if(job) a[u]=-1-du;
	else a[u]=1+du;
}
int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t; while(t--) {
		cin>>n;
		fr(i,1,n) G[i].clear();
		for(int i=1,u,v;i<n;++i) {
			cin>>u>>v,G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0,0);
		fr(i,1,n) cout<<a[i]<<' ';
		cout<<endl;
	}
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