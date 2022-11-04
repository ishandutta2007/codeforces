#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;

bool bit(int s,int i) {return (1ll<<i)&s;}

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

signed main() {
	int T=read();
	rep(t,1,T) {
		int a=read(), b=read(), x=0;
		rep(i,0,30) {
			if(bit(a,i)&&bit(b,i)) x+=(1ll<<i);
		}
		printf("%lld\n",(a^x)+(b^x));
	}
	return 0;
}