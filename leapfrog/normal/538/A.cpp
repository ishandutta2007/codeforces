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
const char mt[15]="?CODEFORCES";char ch[1005];int n;
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);if(n<10) return puts("NO"),0;
	for(int i=0;i<=10;i++)
	{
		char fg=0;for(int j=1;j<=i;j++) if(mt[j]!=ch[j]) fg=1;
		for(int j=i+1;j<=10;j++) if(mt[j]!=ch[n-10+j]) fg=1;
		if(!fg) return puts("YES"),0;
	}
	return puts("NO"),0;
}