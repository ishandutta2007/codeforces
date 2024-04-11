//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
#define int long long
int n,a[100005],v[100005],tp;char ch[15];
const int N=(1ll<<32)-1;ll st[100005];
signed main()
{
	read(n);for(int i=1;i<=n;i++)
	{
		scanf("%s",ch);if(*ch=='f') read(v[i]);
		a[i]=*ch=='f'?0:(*ch=='e'?1:2);
	}
	ll rs=0;st[tp=1]=1;for(int i=1;i<=n;i++)
	{
		if(a[i]==2) {rs+=st[tp];if(rs>N) return puts("OVERFLOW!!!"),0;}
		else if(a[i]==1) tp--;else st[tp+1]=min(1ll*N+1,st[tp]*v[i]),tp++;
	}
	return printf("%lld\n",rs),0;
}