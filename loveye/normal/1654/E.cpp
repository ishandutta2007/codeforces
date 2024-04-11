#include<cstdio>
#include<cmath>
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

const int N=1e5+5,SX=N*317;
int n,a[N],ans;
int cnt[SX<<1];
int main() {
	cin>>n;
	fr(i,1,n) cin>>a[i];
	int sx=sqrt(1e5);
	ans=0;
	fr(d,-sx,sx) {
		fr(i,1,n) {
			++cnt[a[i]-i*d+SX];
			ans=max(ans,cnt[a[i]-i*d+SX]);
		}
		fr(i,1,n) --cnt[a[i]-i*d+SX];
	}
	fr(i,1,n) {
		fr(j,1,min(n-i,sx)) if((a[i+j]-a[i])%j==0) {
			++cnt[(a[i+j]-a[i])/j+SX];
			ans=max(ans,cnt[(a[i+j]-a[i])/j+SX]+1);
		}
		fr(j,1,min(n-i,sx)) if((a[i+j]-a[i])%j==0)
			--cnt[(a[i+j]-a[i])/j+SX];
	}
	cout<<n-ans<<endl;
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