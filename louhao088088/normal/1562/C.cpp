#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=1e5+5;
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
int n,m;
char a[100005];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	while(n--)
	{
		m=read();
		scanf("%s",a+1);
		for(int i=1;i<=m;i++)
		{
			if(a[i]=='0')
			{
				if(i>m/2)
				{
					printf("1 %d 1 %d\n",i,i-1);
				}
				else 
				{
					printf("%d %d %d %d\n",i,m,i+1,m);
				}break;
			}
			if(i==m)
			{
				printf("1 %d 2 %d\n",m-1,m);
			}
		}
	}
 	return 0;
}