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
const int N=1005;char ch[2][N];int n;
inline void solve()
{
	read(n),scanf("%s%s",ch[0]+1,ch[1]+1);
	if(ch[1][n]=='1') return puts("NO"),void();
	for(int i=1;i<=n;i++) if(ch[0][i]=='1'&&ch[1][i]=='1') return puts("NO"),void();
	puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}