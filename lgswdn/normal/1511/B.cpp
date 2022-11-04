#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,a,b,c;

int main() {
	T=read();
	while(T--) {
		int a=read(), b=read(), c=read();
			int x=1,y=1,z=1;
			rep(i,1,a-1) x=x*10;
			rep(i,1,b-1) y=y*10;
			rep(i,1,c-1) z=z*10;
			if(x>y) x+=z;
			else y+=z;
			printf("%d %d\n",x,y);
	}
	return 0;
}