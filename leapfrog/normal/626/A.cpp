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
int n;char s[100005];
int main()
{
	read(n),scanf("%s",s+1);int tot=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		int x=0,y=0;for(int k=i;k<=j;k++)
		{
			if(s[k]=='U') x--;else if(s[k]=='D') x++;
			if(s[k]=='L') y--;else if(s[k]=='R') y++;
		}
		if(!x&&!y) tot++;
	}
	return printf("%d\n",tot),0;
}