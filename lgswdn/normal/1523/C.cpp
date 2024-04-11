#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,a,s[N],top;

int main() {
	T=read();
	while(T--) {
		n=read();
		top=0;
		rep(i,1,n) {
			a=read();
			if(a!=1) {
				while(top&&s[top]!=a-1) top--; top--;
				s[++top]=a;
			} else s[++top]=a;
			rep(i,1,top) {
				printf("%d",s[i]);
				if(i!=top) putchar('.');
			}
			puts("");
		}
	}
	return 0;
}