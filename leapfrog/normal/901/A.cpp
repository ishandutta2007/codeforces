//Coded by leapfrog on 2021.11.04 {{{
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
const int N=200005;int n,h,a[N],fa[N],qwq[N];
int main()
{
	read(h),++h;for(int i=1;i<=h;i++) read(a[i]),n+=a[i];
	int cn=0;qwq[1]=1,cn++;
	for(int i=2;i<=h;i++) for(int j=1;j<=a[i];j++) fa[qwq[i]=++cn]=qwq[i-1];
	for(int i=1;i<h;i++) if(a[i]>1&&a[i+1]>1)
	{
		puts("ambiguous");
		for(int i=1;i<=cn;i++) printf("%d%c",fa[i],i==cn?'\n':' ');
		fa[qwq[i+1]]=qwq[i]-1;
		for(int i=1;i<=cn;i++) printf("%d%c",fa[i],i==cn?'\n':' ');
		return 0;
	}
	return puts("perfect"),0;
}