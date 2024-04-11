#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=1e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,t;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	t=read();
	while(t--)
	{
		n=read(),m=read();
		if(m%3)
		{
			if(n%3==0) puts("Bob");
			else puts("Alice");
		}
		else
		{
			n=n%(m+1);
			if(n==m||n%3>0) puts("Alice");
			else puts("Bob");
		}
	}
 	return 0;
}