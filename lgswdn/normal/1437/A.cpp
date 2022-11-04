#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int t,l,r;

signed main() {
	t=read();
	while(t--) {
		l=read(), r=read();
		int x=l*2;
		if(r<x) puts("YES");
		else puts("NO");
	}
	return 0;
}
//