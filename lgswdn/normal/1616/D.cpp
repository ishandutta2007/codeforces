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

const int N=3e5+9;
int T,n,a[N],x;

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read();
		x=read();
		rep(i,1,n) a[i]-=x;
		int ans=n;
		rep(i,2,n) if(a[i]+a[i-1]<0||a[i]+a[i-1]+a[i-2]<0) ans--, a[i]=0x3f3f3f3f;
		printf("%lld\n",ans);
	}
	return 0;
}