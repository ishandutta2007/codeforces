//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
#define mk make_pair
using namespace std; const int N=600010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
signed main()
{
	for(ri int T=read();T;T--)
	{
		int a,b,c,d;
		a=read(), b=read(), c=read(), d=read();
		int qwq=((a+b)&1ll);
		if((a||d) && qwq) printf("Ya ");
		else printf("Tidak ");
		if((b||c) && qwq) printf("Ya ");
		else printf("Tidak ");
		if((b||c) && (!qwq)) printf("Ya ");
		else printf("Tidak ");
		if((a||d) && (!qwq)) printf("Ya ");
		else printf("Tidak ");
		puts("");
	}
    return 0;
}