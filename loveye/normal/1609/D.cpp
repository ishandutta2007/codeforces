#include<cstdio>
#include<set>
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

const int N=1e3+5;
int n,d;
multiset<int,greater<int> > s;
int f[N],siz[N],cps; int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
#define Erase(x) s.erase(s.find(x))
void merge(int x,int y) {
	x=getf(x),y=getf(y);
	if(x!=y) {
		Erase(siz[y]);
		Erase(siz[x]);
		f[x]=y,siz[y]+=siz[x];
		--cps;
		s.insert(siz[y]);
	}
}
int main() {
	cin>>n>>d;
	fr(i,1,n) f[i]=i,siz[i]=1,s.insert(1); cps=n;
	fr(i,1,d) {
		static int u,v;
		cin>>u>>v;
		merge(u,v);
		int rest=i-(n-cps)+1;
		assert(1<=rest&&rest<=s.size());
		int sum=0; auto it=s.begin();
		fr(i,1,rest) sum+=*it,++it;
		cout<<sum-1<<endl;
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