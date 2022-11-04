#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,x,a[N],m,f[409][N];

int main() {
	n=read(), x=pow(n,0.5);
	rep(i,1,n) a[i]=read();
	rep(i,1,x) {
		per(j,n,1) f[i][j]=(j+a[j]+i>n?1:f[i][j+a[j]+i]+1);
	}
	m=read();
	while(m--) {
		int p=read(), k=read();
		if(k<=x) printf("%d\n",f[k][p]);
		else {
			int cnt=0;
			while(p<=n) cnt++, p=p+a[p]+k;
			printf("%d\n",cnt);
		}
	}
	return 0;
}