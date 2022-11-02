//Coded by Kamiyama_Shiki on 2021.11.03 {{{
//
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
int n,m;char ch[1000005];
inline void solve()
{
	read(n,m),scanf("%s",ch+1);
	int x=1,y=1,mnx=1,mxx=1,mny=1,mxy=1,px=1,py=1;
	for(int i=1,t=strlen(ch+1);i<=t;i++)
	{
		if(ch[i]=='L') y--;else if(ch[i]=='R') y++;
		if(ch[i]=='U') x--;else if(ch[i]=='D') x++;
		mnx=min(mnx,x),mny=min(mny,y),mxx=max(mxx,x),mxy=max(mxy,y);
		if(mxx-mnx>=n||mxy-mny>=m) return printf("%d %d\n",px,py),void();
		px=2-mnx,py=2-mny;
	}printf("%d %d\n",px,py);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}