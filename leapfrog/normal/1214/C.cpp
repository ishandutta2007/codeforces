//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
char ch[2000005];int n;
int main()
{
	read(n),scanf("%s",ch+1);int nw=0;
	for(int i=1;i<=n;i++)
	{
		if(ch[i]=='(') nw++;else nw--;
		if(nw<-1) return puts("No"),0;
	}
	if(nw) return puts("No"),0;else puts("Yes");
}