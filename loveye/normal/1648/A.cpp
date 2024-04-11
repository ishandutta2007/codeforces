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
int n,m;
vector<int> a[N];
int c[N],d[N];
int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	fr(i,1,n) {
		a[i].resize(m+1);
		fr(j,1,m) {
			cin>>a[i][j];
			++c[a[i][j]];
		}
	}
	ll ans=0,res=0;
	fr(i,1,n) {
		fr(j,1,m) {
			res-=1ll*d[a[i][j]]*(c[a[i][j]]-d[a[i][j]]);
			++d[a[i][j]];
			res+=1ll*d[a[i][j]]*(c[a[i][j]]-d[a[i][j]]);
		}
		ans+=res;
	}
	memset(d,0,sizeof d);
	fr(i,1,m) {
		fr(j,1,n) {
			res-=1ll*d[a[j][i]]*(c[a[j][i]]-d[a[j][i]]);
			++d[a[j][i]];
			res+=1ll*d[a[j][i]]*(c[a[j][i]]-d[a[j][i]]);
		}
		ans+=res;
	}
	cout<<ans<<endl;
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