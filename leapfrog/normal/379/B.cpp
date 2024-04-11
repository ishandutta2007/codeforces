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
const int N=305;int n,a[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int nw=1;for(int i=1;i<=n;i++)
	{
		while(nw<i) putchar('R'),nw++;
		while(a[i])
		{
			a[nw]--,putchar('P');
			if(i==n) putchar('L'),nw--;else putchar('R'),nw++;
			if(a[nw]) putchar('P'),a[nw]--;
			if(i==n) putchar('R'),nw++;else putchar('L'),nw--;
		}
	}return putchar('\n'),0;
}