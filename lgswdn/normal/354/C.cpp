#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e6+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,k,m=0x3f3f3f3f,mx,a[N],c[N];

int main() {
	n=read(), k=read();
	rep(i,1,n) a[i]=read(), m=min(m,a[i]), mx=max(mx,a[i]);
	if(m<=k+1) {
		printf("%d\n",m);
		return 0;
	}
	rep(i,1,n) c[a[i]]++;
	rep(i,1,mx+k) c[i]+=c[i-1];
	per(g,m,k+1) {
		int cnt=0;
		for(int d=g;d<=mx;d+=g) cnt+=(c[d+k]-c[d-1]);
		if(cnt==n) {printf("%d\n",g); break;}
	}
	return 0;
}