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
int n,m;char ch[2000005];
inline void solve()
{
	read(n),scanf("%s",ch+1);
	for(int i=1;i<=n;i++) if(ch[i]=='?')
	{
		int l=i,r=i;while(ch[r+1]=='?') r++;
		//printf("? %d %d\n",l,r);
		char fg;if(l==1&&r==n) fg='R';else if(l==1)
		{
			fg='R'^'B'^ch[r+1];
			if((r-l)&1) fg^='R'^'B';
		}else fg='R'^'B'^ch[l-1];
		for(int j=l;j<=r;j++) ch[j]=(j-l)&1?fg^'R'^'B':fg;
		i=r+1;
	}
	for(int i=1;i<=n;i++) putchar(ch[i]);
	putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}