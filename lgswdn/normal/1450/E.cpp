#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2009;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,d[N][N],a[N],b[N],ans=-1,st;

int main() {
	n=read(), m=read();
	memset(d,0x3f,sizeof(d));
	rep(i,1,m) {
		int u=read(), v=read(), c=read();
		if(c) d[u][v]=1, d[v][u]=-1;
		else d[u][v]=1, d[v][u]=1;
		a[i]=u,b[i]=v;
	}
	rep(i,1,n) d[i][i]=0;
	rep(k,1,n) rep(i,1,n) rep(j,1,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	rep(i,1,n) {
		if(d[i][i]<0) return puts("NO"), 0;
		bool flag=0;
		rep(j,1,m) if(d[i][a[j]]==d[i][b[j]]) flag=1;
		if(flag) continue;
		int x=0,y=0;
		rep(j,1,n) x=max(x,d[i][j]),y=min(y,d[i][j]);
		if(x-y>ans) st=i,ans=x-y;
	}
	if(ans==-1) return puts("NO"), 0;
	printf("YES\n%d\n",ans);
	rep(i,1,n) printf("%d ",d[st][i]+ans);
	return 0;
}