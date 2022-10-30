//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a,x,b,y;
signed main()
{
	n=read(), a=read(), x=read(), b=read(), y=read();
	while(a!=x && b!=y)
	{
		if(a==b) { puts("YES"); return 0; }
		if(a^x)
		{
			a++;
			if(a>n) a=1;
		}
		if(b^y)
		{
			b--;
			if(!b) b=n;
		}
	}
	if(a==b) puts("YES");
	else puts("NO");
    return 0;
}