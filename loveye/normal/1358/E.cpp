#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=5e5+5;
int n,a[N],b[N],x;
ll s[N];
int main() {
	scanf("%d",&n);
	int k=n+1>>1;
	fr(i,1,k) scanf("%d",a+i);
	scanf("%d",&x);
	if(x>=0) {
		ll sum=1ll*(n-k)*x;
		fr(i,1,k) sum+=a[i];
		if(sum>0) printf("%d\n",n);
		else puts("-1");
	} else {
		rf(i,k,1) {
			s[i]=s[i+1]+a[i];
			ll l=k-i+1+max((s[i]+(-x)-1)/(-x),0ll);
			if(l<=n-i+1) ++b[l],--b[n-i+2];
		}
		fr(i,1,n) {
			b[i]+=b[i-1];
			if(i>n/2&&b[i]==0) return printf("%d\n",i),0;
		}
		puts("-1");
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}