//Coded by leap_frog on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=2005;int n,a[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int rs=1e9;for(int i=1,tg=0;i<=n;i++)
	{
		map<int,int>fg;for(int j=1;j<i;j++) if(fg[a[j]]) tg=1;else fg[a[j]]=1;
		if(!tg) for(int j=n;j>=i-1;j--) {rs=min(rs,j-i+1);if(fg[a[j]]) break;else fg[a[j]]=1;}
	}return printf("%d\n",rs),0;
}