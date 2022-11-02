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
int T,n,m;char ch[505][505];
inline void solve()
{
	read(n),read(m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i+2<=n;i+=3)
	{
		int tg=0;for(int j=1;j<=m;j++) ch[i][j]='X';
		if(i+1<=n) for(int j=1;j<=m&&!tg;j++) if(ch[i+1][j]=='X') tg=j;
		if(i+2<=n) for(int j=1;j<=m&&!tg;j++) if(ch[i+2][j]=='X') tg=j;
		tg?0:tg=1,ch[i+1][tg]=ch[i+2][tg]='X';
	}
	int qwq=(n-1)/3*3+1;for(int i=1;i<=m;i++) ch[qwq][i]='X';
	if(qwq+2<=n) for(int i=1;i<=m;i++) if(ch[qwq+2][i]=='X') ch[qwq+1][i]='X';
	for(int i=1;i<=n;i++) printf("%s\n",ch[i]+1);
}
int main() {for(read(T);T--;) solve();return 0;}