#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=109;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int a[N];

int main() {
	int T=read();
	while(T--) {
		int n=read();
		rep(i,1,n) a[i]=n-i+1;
		if(n%2==1) swap(a[n/2],a[n/2+1]);
		rep(i,1,n) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}