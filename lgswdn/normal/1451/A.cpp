#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,ans;

int main() {
	T=read();
	while(T--) {
		n=read();
		ans=0;
		if(n==1) ans=0;
		else if(n==2) ans=1;
		else if(n==3) ans=2;
		else if(n%2==0) ans=2;
		else ans=3;
		printf("%d\n",ans);
	}
	return 0;
}//