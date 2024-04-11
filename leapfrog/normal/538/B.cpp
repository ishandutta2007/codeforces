//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
char ch[105];int n;
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);for(int i=1;i<=n;i++) ch[i]^=48;
	int mx=0;for(int i=1;i<=n;i++) mx=max(mx,(int)ch[i]);
	printf("%d\n",mx);for(int i=1,st=1;i<=mx;i++,putchar(' '),st=1)
		for(int j=1;j<=n;j++) if(ch[j]) putchar('1'),ch[j]--,st=0;else if(!st) putchar('0');
	return putchar('\n'),0;
}