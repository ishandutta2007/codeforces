//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}mt19937 rnd(time(0));int n,tot;
inline int qry(int l,int r)
{
	putchar('?'),putchar(' ');for(int i=1;i<=n;i++) putchar(48|(i>=l&&i<=r));
	putchar('\n'),fflush(stdout);int x;return read(x),x;
}
inline int solve(int l,int r,int qwq)
{
	int md=(l+r)>>1;if(l==r) return l;
	if(qry(l,md)+(md-l+1)*((qwq<<1)-1)==tot) return solve(md+1,r,qwq);else return solve(l,md,qwq);
}
int main()
{
	read(n),tot=qry(0,0);int tt=qry(n,n);
	if(tt==tot+1) printf("! %d %d\n",n,solve(1,n-1,0));else printf("! %d %d\n",solve(1,n-1,1),n);
	return 0;
}