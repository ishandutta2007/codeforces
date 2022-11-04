#include<bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

inline long long read() {
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-48; c=getchar();}
	return x*f;
}

int T,n;

signed main() {
	T=read();
	while(T--) {
		n=read();
		if(n%2==1) n++;
		n/=2;
		if(n<=3) printf("%lld\n",15ll);
		else printf("%lld\n",n*5);
	}
	return 0;
}