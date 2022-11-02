//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int Ca,n,at;char ch[1005][1005];struct node{int x,y;}a[100005];
inline void solve()
{
	read(n),at=0;for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(ch[i][j]=='*') a[++at]=(node){i,j};
	a[++at]=a[1],a[++at]=a[2];
	if(a[1].x==a[2].x) a[at-1].x=a[at-1].x%n+1,a[at].x=a[at].x%n+1;
	else if(a[1].y==a[2].y) a[at-1].y=a[at-1].y%n+1,a[at].y=a[at].y%n+1;
	else swap(a[at-1].x,a[at].x);
	ch[a[at-1].x][a[at-1].y]=ch[a[at].x][a[at].y]='*';
	for(int i=1;i<=n;i++) printf("%s\n",ch[i]+1);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}