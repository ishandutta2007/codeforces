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

const int N=3e5+5,NN=N*31;
int n,a[N];
int nds,ch[NN][2],siz[NN];
void Insert(int x) {
	int cur=0;
	rf(i,29,0) {
		int &son=ch[cur][x>>i&1];
		if(!son) son=++nds;
		++siz[cur=son];
	}
}
int query(int x) {
	int y=0,cur=0;
	rf(i,29,0) {
		int d=x>>i&1;
		int son=ch[cur][d];
		if(siz[son]) --siz[cur=son];
		else --siz[cur=ch[cur][d^1]],y|=1<<i;
	}
	return y;
}
int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	fr(i,1,n) cin>>a[i];
	int b; fr(i,1,n) cin>>b,Insert(b);
	fr(i,1,n) cout<<query(a[i])<<' ';
	cout<<endl;
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