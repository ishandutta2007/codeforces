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
int n,m;char ch[100005];ll rs=0;
int main()
{
	read(n,m),scanf("%s",ch+1),rs=1ll*n*(m-1);
	for(int i=2,nw=0;i<=n;i++)
	{
		if(i>2&&ch[i]==ch[i-2]) nw++;else nw=0;
		if(ch[i]!=ch[i-1]) rs+=1ll*n*(m-1)-nw-1;
	}return printf("%lld\n",rs),0;
}