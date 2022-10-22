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

const int N=3e5+5;
int n,a[N],p[N],q[N];
ll f[35][2];
void solve(int l,int r,int k) {
	if(k<0) return;
	if(r-l+1<=1) return;
	int pt1=l,pt2=r;
	fr(i,l,r) if(~a[p[i]]>>k&1) q[pt1++]=p[i];
	else q[pt2--]=p[i];
	reverse(q+pt1,q+r+1);
	fr(i,l,r) p[i]=q[i];
	int x=pt1;
	fr(i,l,pt1-1) {
		while(x<=r&&p[x]<p[i]) ++x;
		f[k][1]+=r-x+1;
		f[k][0]+=x-pt1;
	}
	solve(l,pt1-1,k-1);
	solve(pt1,r,k-1);
}
int main() {
	scanf("%d",&n);
	fr(i,1,n) scanf("%d",a+i),p[i]=i;
	solve(1,n,30);
	ll ans=0; int x=0;
	fr(i,0,30) if(f[i][0]<=f[i][1]) ans+=f[i][0];
	else ans+=f[i][1],x|=1<<i;
	printf("%lld %d\n",ans,x);
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