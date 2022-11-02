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
int T,s,b[55],s1,s2,n;
char a[55];
bool check(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)return 1;
	}return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T)
	{
		T--;
		n=read();int F=0;s1=0,s2=0;
		scanf("%s",a+1);
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i]-'0';
			if(b[i]==4||b[i]==6||b[i]==8||b[i]==9||b[i]==1)
			{
				puts("1"),cout<<b[i]<<endl;F=1;break;
			}
		}if(F==1)continue;
		for(int i=1;i<=n;i++)
		{
			if(F)break;
			for(int j=i+1;j<=n;j++)
			{
				if(check(b[i]*10+b[j]))
				{
					F=1;puts("2");cout<<b[i]<<b[j]<<endl;break;
				}
			}
		}
		
	}
 	return 0;
}