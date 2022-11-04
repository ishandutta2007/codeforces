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

int n,m,nxt[N],ans[N];

int go(int u) {return nxt[u]==u?u:nxt[u]=go(nxt[u]);}

int main() {
	n=read(), m=read();
	rep(i,0,n+1) nxt[i]=i;
	rep(i,1,m) {
		int l=read(), r=read(), x=read();
		int pos=go(l);
		while(pos<=r) {
			if(pos!=x) ans[pos]=x,nxt[pos]=pos+1;
			pos=go(pos+1);
		}
	}
	rep(i,1,n) printf("%d ",ans[i]); puts("");
	return 0;
}