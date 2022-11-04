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

const int N=109;
int T,n,a[N],b[N],f[N][N*N],g[N*N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		int sum=0;
		rep(i,1,n) a[i]=read(), sum+=a[i];
		rep(i,1,n) b[i]=read(), sum+=b[i];
		int ans=0;
		rep(i,1,n) ans=ans+a[i]*a[i];
		rep(i,1,n) ans=ans+b[i]*b[i];
		rep(i,1,n) rep(j,0,10000) f[i][j]=0;
		f[0][0]=1;
		rep(i,1,n) {
			rep(j,0,10000) {
				if(j>=a[i]) f[i][j]|=f[i-1][j-a[i]];
				if(j>=b[i]) f[i][j]|=f[i-1][j-b[i]];
			}
		}
		int cans=0x3f3f3f3f3f3f3f3f;
		rep(j,0,10000) {
			if(f[n][j]) cans=min(cans,j*j+(sum-j)*(sum-j));
		}
		printf("%lld\n",(n-2)*ans+cans);
	}
	return 0;
}