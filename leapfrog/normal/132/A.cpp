//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
char ch[1000005];int n;
int main()
{
	char c=getchar();for(;c!='\n';c=getchar()) ch[++n]=c;
	for(int i=1,ls=0;i<=n;i++)
	{
		int v=128,x=ch[i],w=0;
		while(x) w+=v*(x&1),v>>=1,x>>=1;
		printf("%d\n",(ls-w+256)%256),ls=w;
	}
	return 0;
}