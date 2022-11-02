//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=555;int n,id[N];char ch[N],a[N][N];
inline void solve()
{
	read(n),scanf("%s",ch+1);int it=0;memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) if(ch[i]=='2') id[++it]=i;
	if(it==1||it==2) return puts("NO"),void();else puts("YES");
	for(int i=1;i<=it;i++) a[id[i]][id[i%it+1]]=1,a[id[i%it+1]][id[i]]=-1;
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=n;j++)
		putchar(i==j?'X':(a[i][j]==1?'+':(a[i][j]==-1?'-':'=')));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}