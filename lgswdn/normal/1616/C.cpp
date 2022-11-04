#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define jmp(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define pmj(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();} 
	return res*w;
}

const int N=1e5+9;
int T,n,a[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read();
		if(n==1) {
			puts("0");
			continue;
		}
		int ans=n;
		rep(l,1,n) rep(r,l+1,n) {
			double d=1.*(a[r]-a[l])/(r-l),x=a[l]-d*(l-1);
			int cur=0;
			rep(i,1,n) {
				if(fabs(a[i]-x)>1e-6) cur++;
				x+=d;
			}
			ans=min(ans,cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
}