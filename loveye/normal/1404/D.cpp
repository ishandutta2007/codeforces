#include<cstdio>
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

const int N=(5e5+5)*2;
int n,a[N],p[N],res[N],col[N];
int to[N<<1],nxt[N<<1],eds,fir[N];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
void dfs(int u,int c) {
	col[u]=c;
	foredge(i,u,v) if(col[v]==-1) dfs(v,c^1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n&1) {
		cout<<"Second"<<endl;
		fr(i,1,2*n) {
			cin>>p[i];
			if(res[p[i]]) {
				addedge(res[p[i]],i);
				addedge(i,res[p[i]]);
			} else res[p[i]]=i;
		}
		fr(i,1,n) addedge(i,i+n),addedge(i+n,i);
		memset(col,-1,sizeof col);
		fr(i,1,2*n) if(col[i]==-1) dfs(i,0);
		ll sum=0;
		fr(i,1,2*n) if(col[i]==0) sum+=i;
		if(sum%(2*n)==0) {
			fr(i,1,2*n) if(col[i]==0) cout<<i<<' ';
			cout<<endl;
		} else {
			fr(i,1,2*n) if(col[i]==1) cout<<i<<' ';
			cout<<endl;
		}
	} else {
		cout<<"First"<<endl;
		fr(i,1,n) cout<<i<<' ';
		fr(i,1,n) cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}