//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,buf[8000005],*a[500005],rs[500005],V[5000005],W[5000005];
inline int ckln(int x,int fg=0) {int res=0;for(int i=1;i<=m;i++) if(i!=fg) res+=rs[i]!=a[x][i];return res;}
inline char ckrs() {for(int i=1;i<=n;i++) if(ckln(i)>2) return 0;return 1;}
inline void solve()
{
	read(n),read(m),a[1]=buf;int mx=0,wh=0;
	for(int i=2;i<=n;i++) a[i]=a[i-1]+m+5;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	for(int i=1;i<=m;i++) rs[i]=a[1][i];
	for(int i=2;i<=n;i++) {int qwq=ckln(i);if(qwq>=mx) mx=qwq,wh=i;}
	if(mx>4) return puts("No"),void();
	if(mx<=2) {puts("Yes");for(int i=1;i<=m;i++) printf("%d%c",rs[i],i==m?'\n':' ');return;}
	if(mx==4)
	{
		int tn[5],cn=0;
		for(int i=1;i<=m;i++) if(a[1][i]!=a[wh][i]) tn[++cn]=i;
		for(int i=1;i<=cn;i++) for(int j=i+1;j<=cn;j++)
		{
			int t1=rs[tn[i]],t2=rs[tn[j]];rs[tn[i]]=a[wh][tn[i]],rs[tn[j]]=a[wh][tn[j]];
			if(ckrs()) {puts("Yes");for(int k=1;k<=m;k++) printf("%d%c",rs[k],k==m?'\n':' ');return;}
			rs[tn[i]]=t1,rs[tn[j]]=t2;
		}
		puts("No");return;
	}
	int tn[5],cn=0;for(int i=1;i<=m;i++) if(a[1][i]!=a[wh][i]) tn[++cn]=i;
	for(int I=1;I<=cn;I++) for(int J=1;J<=cn;J++) if(I!=J)
	{
		int qw1=tn[I],qw2=tn[J],no=tn[1]+tn[2]+tn[3]-qw1-qw2,mx=0,ggg=rs[qw1],H=-1,tag=1;
		rs[qw1]=a[wh][qw1];for(int i=1;i<=n;i++) V[i]=ckln(i,no),W[i]=a[i][no],mx=max(mx,V[i]);
		if(mx<=1) {puts("Yes");for(int i=1;i<=m;i++) printf("%d%c",rs[i],i==m?'\n':' ');return;}
		if(mx>=3) {rs[qw1]=ggg;continue;}
		for(int i=1;i<=n;i++) if(V[i]==2) {if(H==-1) H=a[i][no];else if(a[i][no]!=H) tag=0;}
		if(tag) {puts("Yes");for(int i=1;i<=m;i++) if(i==no) printf("%d ",H==-1?1:H);else printf("%d ",rs[i]);return putchar('\n'),void();}
		rs[qw1]=ggg;
	}
	puts("No");
}
//int main() {for(read(T);T--;) solve();return 0;}
int main() {return solve(),0;}