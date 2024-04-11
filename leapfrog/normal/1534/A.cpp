//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m;char ch[55][55];
inline void solve()
{
	read(n),read(m);char c[2]={'R','W'};
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	char fg=0;for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if(ch[i][j]!='.'&&ch[i][j]!=c[(i+j)&1]) fg=1;
	if(!fg)
	{
		puts("YES");for(int i=1;i<=n;i++,putchar('\n'))
			for(int j=1;j<=m;j++) putchar(c[(i+j)&1]);
		return;
	}else swap(c[0],c[1]);
	fg=0;for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if(ch[i][j]!='.'&&ch[i][j]!=c[(i+j)&1]) fg=1;
	if(!fg)
	{
		puts("YES");for(int i=1;i<=n;i++,putchar('\n'))
			for(int j=1;j<=m;j++) putchar(c[(i+j)&1]);
		return;
	}else puts("NO");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}