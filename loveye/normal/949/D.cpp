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
int n,d,b;
int a[N],c[N];
int L,R,M;
int chkleft(ll res) {
	fr(i,M+1,n) {
		c[i]=min(0ll+a[i],res);
		res-=c[i];
	}
	fr(i,1,M) c[i]=a[i];
	ll tmp=0; int pt=1;
	fr(i,1,M) {
		while(pt<=n&&pt-i<=1ll*i*d)
			tmp+=c[pt++];
		if(i>=L) {
			if(tmp<b) return 0;
			tmp-=b;
		}
	}
	return 1;
}
int chkright(ll res) {
	rf(i,M,1) {
		c[i]=min(0ll+a[i],res);
		res-=c[i];
	}
	fr(i,M+1,n) c[i]=a[i];
	ll tmp=0; int pt=n;
	rf(i,n,M+1) {
		while(pt>=1&&i-pt<=1ll*(n-i+1)*d)
			tmp+=c[pt--];
		if(i<=R) {
			if(tmp<b) return 0;
			tmp-=b;
		}
	}
	return 1;
}
int chk(int x) {
	L=x+1,R=n-x,M=n+1>>1;
	ll sumL=0,sumR=0;
	fr(i,1,M) sumL+=a[i];
	fr(i,M+1,n) sumR+=a[i];
	return chkleft(max(sumR-1ll*(R-M)*b,0ll))&&
		chkright(max(sumL-1ll*(M-L+1)*b,0ll));
}
int main() {
	cin>>n>>d>>b;
	fr(i,1,n) cin>>a[i];
	int l=0,r=n>>1;
	//cout<<chk(1)<<endl;
	while(l<r) {
		int mid=l+r>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
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