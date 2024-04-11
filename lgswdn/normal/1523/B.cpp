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

int T,n,a;

int main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a=read();
		printf("%d\n",n*3);
		for(int i=1;i<=n;i+=2) {
			printf("1 %d %d\n2 %d %d\n1 %d %d\n1 %d %d\n2 %d %d\n1 %d %d\n",i,i+1,i,i+1,i,i+1,i,i+1,i,i+1,i,i+1);
		}
	}
	return 0;
}