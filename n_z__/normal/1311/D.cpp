#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
inline int Read()
{
    register int Return,Flag;
    Return=0,Flag=1;
    register char C;
    C=getchar();
    while(!isdigit(C))
    {
        if(C=='-')
        {
            Flag=-1;
        }
        C=getchar();
    }
    while(isdigit(C))
    {
        Return=(Return<<1)+(Return<<3)+(C^'0');
        C=getchar(); 
    }
    return Return*Flag;
}
inline void Write(int X)
{
    if(X<0)
    {
        X=-X;
        putchar('-');
    }
    if(X>9)
    {
        Write(X/10);
    }
    putchar(X%10^48);
}
using namespace std;
#define int long long
signed main() {
	int t=Read();
	while(t--){
		int a=Read(),b=Read(),c=Read();
		int ana=0,anb=0,anc=0,ans=10000000000;
		for(int x=1;x<=1e4;x++)
		for(int y=x;y<=1e5;y+=x)
		for(int z=y;z<=1e5;z+=y)
		if(abs(a-x)+abs(b-y)+abs(c-z)<ans)ans=abs(a-x)+abs(b-y)+abs(c-z),ana=x,anb=y,anc=z;
		Write(ans);
		puts("");
		Write(ana);
		putchar(' ');
		Write(anb);
		putchar(' ');
		Write(anc);
		puts("");
	}
}