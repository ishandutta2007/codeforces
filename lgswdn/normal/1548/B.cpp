#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e6+9;
int T,n,a[N],g[N][29];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read();
		per(i,n,1) a[i]=abs(a[i]-a[i-1]);
		if(n==1) {puts("1"); continue;}
		rep(i,1,n) rep(j,0,20) g[i][j]=0;
		int ans=0;
		per(i,n,2) {
			g[i][0]=a[i];
			rep(j,1,20) if(i+(1<<j)-1<=n) g[i][j]=__gcd(g[i][j-1],g[i+(1<<j-1)][j-1]);
			int r=i,s=a[i];
			per(j,20,0) if(r+(1<<j)-1<=n&&__gcd(s,g[r][j])!=1) s=__gcd(s,g[r][j]), r=r+(1<<j);
			ans=max(ans,r-i+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}