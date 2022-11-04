#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=3e5+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,q,a[N],c[N];

int main() {
	n=read(), q=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) if(!c[a[i]]) c[a[i]]=i;
	rep(i,1,q) {
		int t=read();
		int pos=c[t];
		printf("%d ",pos);
		rep(i,1,50) if(c[i]<pos) c[i]++;
		c[t]=1;
	}
	return 0;
}