//Coded by leapfrog {{{
//Gened on 2021.10.25 10:02:40
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
const int N=1005;int n;char ch[N];
int main()
{
	read(n),scanf("%s",ch+1);
	for(int i=2;i<=n;i++) if(ch[i]!=ch[i-1])
		return printf("YES\n%c%c\n",ch[i-1],ch[i]),0;
	return puts("NO"),0;
}