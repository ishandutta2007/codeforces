#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2009,lim=1e6,M=1e6+9;

int n,m,a[N],b[N],c[N],d[N],h[M],p[M],s[M];

signed main() {
	n=read(), m=read();
	rep(i,1,n) a[i]=read(), b[i]=read();
	rep(i,1,m) c[i]=read(), d[i]=read(), h[c[i]]=max(h[c[i]],d[i]);
	rep(i,1,n) {
		rep(j,1,m) if(d[j]>=b[i]) {
			s[d[j]-b[i]]=max(s[d[j]-b[i]],c[j]-a[i]+1);
		}
	}
	int ans=lim+1;
	per(i,lim,0) s[i]=max(s[i],s[i+1]);
	rep(i,0,lim) ans=min(ans,i+s[i]);
	printf("%lld\n",ans);
	return 0;
}