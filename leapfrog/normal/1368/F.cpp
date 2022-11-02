//Coded by Kamiyama_Shiki on 2021.11.03 {{{
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
int n,K;char vs[10005];
inline int Calc(int k) {return n-k-(n-1)/k;}
int main()
{
	read(n);int mx=1,cnt=0;
	for(int i=1;i<=n;i++) if(Calc(mx)<Calc(i)) mx=i;
	if(Calc(mx)<=0) return puts("0"),0;
	while(1)
	{
		printf("%d ",mx);int res=mx;
		for(int i=1;i<=n;i++) if(i%mx!=1&&!vs[i]&&res-->0) vs[i]=1,cnt++,printf("%d ",i);
		putchar('\n'),fflush(stdout);int w;read(w);
		for(int i=1,ps;i<=mx;i++) ps=(i+w-2)%n+1,cnt-=vs[ps],vs[ps]=0;
		if(cnt==Calc(mx)) return puts("0"),fflush(stdout),0;
	}
}