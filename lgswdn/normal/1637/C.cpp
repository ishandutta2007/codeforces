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
int T,a[N],n,lst[N],nxt[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read();
		int ans=0;
		rep(i,2,n-1) ans+=(a[i]+1)/2;
		if(n==3&&a[2]%2==1) {
			puts("-1");
			continue;
		}
		bool a1=1;
		rep(i,2,n-1) if(a[i]!=1) a1=0;
		if(a1) {
			puts("-1");
			continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}