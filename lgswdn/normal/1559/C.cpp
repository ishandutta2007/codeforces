#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,a[N];

signed main() {
	T=read();
	while(T--) {
		n=read(); 
		rep(i,1,n) a[i]=read();
		if(a[1]==1) {
			printf("%lld ",n+1);
			rep(i,1,n) printf("%lld ",i);
			puts("");
		} else if(a[n]==0) {
			rep(i,1,n) printf("%lld ",i);
			printf("%lld ",n+1);
			puts("");
		} else {
			int pos=0;
			rep(i,1,n-1) if(a[i]==0&&a[i+1]==1) {pos=i; break;}
			rep(i,1,pos) printf("%lld ",i);
			printf("%lld ",n+1);
			rep(i,pos+1,n) printf("%lld ",i);
			puts("");
		}
	}
	return 0;
}