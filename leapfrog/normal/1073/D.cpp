//Coded by leapfrog {{{
//Gened on 2021.10.25
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
int n,a[200005];ll T,rs=0;
int main()
{
	read(n,T);for(int i=1;i<=n;i++) read(a[i]);
	int _=1;while(0^_^0)
	{
		int cnt=0;ll sum=0;
		for(int i=1;i<=n;i++) if(sum+a[i]<=T) sum+=a[i],cnt++;
		if(sum) rs+=(T/sum)*cnt,T%=sum;else break;
	}return printf("%lld\n",rs),0;
}