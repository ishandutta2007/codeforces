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

int main() {
	int T=read();
	while(T--) {
		int n=read(), k=read();
		while(k>3) k--, n--, putchar('1'), putchar(' ');
		if(n%4==0) printf("%d %d %d\n",n/2,n/4,n/4);
		else if(n%2==0) printf("%d %d %d\n",2,(n-2)/2,(n-2)/2);
		else printf("%d %d %d\n",1,(n-1)/2,(n-1)/2);
	}
	return 0;
}