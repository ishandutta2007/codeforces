#include<bits/stdc++.h>
using namespace std;typedef long long ll;
const signed N=1e3+5,inf=(int)0x3f3f3f3f3f3f3f3f;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,ans[N*N];char ch[N][N];
inline void solve()
{
	read(n);read(m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	if(m%2==1) {puts("YES");for (int i=1;i<=m+1;i++) printf("%d%c",(i&1?1:2),i==m+1?'\n':' ');return;}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(ch[i][j]==ch[j][i])
		{puts("YES");for(int k=1;k<=m+1;k++) printf("%d%c",(k&1?i:j),k==m+1?'\n':' ');return;}
	if(n==2) {puts("NO");return;}
	if(m%4==2)
	{
		int x,y,z;if(ch[2][3]==ch[3][1]) x=2,y=3,z=1;else if(ch[1][2]==ch[2][3]) x=1,y=2,z=3;else if(ch[3][1]==ch[1][2]) x=3,y=1,z=2;
		puts("YES");for(int i=1;i<=m+1;i++) printf("%d%c",i%2==0?y:(i%4==1?x:z),i==m+1?'\n':' ');
		return;
	}
	int x,y,z;
	if(ch[2][3]==ch[3][1]) x=2,y=3,z=1;else if(ch[1][2]==ch[2][3]) x=1,y=2,z=3;else if(ch[3][1]==ch[1][2]) x=3,y=1,z=2;
	puts("YES");for(int i=1;i<=m+1;i++) printf("%d%c",i%2==1?y:(i%4==2?x:z),i==m+1?'\n':' ');
}
signed main() {for(read(T);T--;) solve();return 0;}