#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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
int n,m,T,a[maxn][15];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=5;j++)a[i][j]=read();
		int flag=0;
		for(int j=1;j<=5;j++)
			for(int k=j+1;k<=5;k++)
			{
				if(flag)break;
				int F=0,s1=0,s2=0;
				for(int i=1;i<=n;i++)
					if(a[i][j]==0&&a[i][k]==0)F=1;
					else
					{
						if(a[i][j]==1)s1++;
						if(a[i][k]==1)s2++;
					}
				if(s1>=n/2&&s2>=n/2&&!F)
				{
					puts("YES");flag=1;
					break;
				}
			}
		if(!flag)puts("NO");
	}
 	return 0;
}