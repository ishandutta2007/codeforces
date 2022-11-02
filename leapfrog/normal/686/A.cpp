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
const int N=1005;
int main()
{
	int n,tt=0;ll X;char ch[5];read(n,X);
	for(int i=1,d;i<=n;i++)
	{
		scanf("%s",ch),read(d);
		if(*ch=='-') X<d?tt++:X-=d;else X+=d;
	}return printf("%lld %d\n",X,tt),0;
}