//Coded by leapfrog on 2021.10.28 {{{
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
int main()
{
	int n;read(n);
	if(n<=3) return puts("NO"),0;
	if(n&1)
	{
		puts("YES");
		puts("3 - 1 = 2");
		puts("2 * 2 = 4");
		puts("4 * 5 = 20");
		puts("20 + 4 = 24");
		for(int i=6;i<=n;i+=2) printf("%d - %d = 1\n24 * 1 = 24\n",i+1,i);
	}//(3-1)*5*2+4
	else
	{
		puts("YES");
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		for(int i=5;i<=n;i+=2) printf("%d - %d = 1\n24 * 1 = 24\n",i+1,i);
		return 0;
	}
}