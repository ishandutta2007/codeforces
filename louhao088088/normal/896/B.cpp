#include<bits/stdc++.h>
using namespace std;
static char buf[1000000],*p1=buf,*p2=buf;
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
int n,m,c,a[maxn],b[maxn],tl,tr,x;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),c=read();tr=n+1,tl=0;
	while(m--)
	{
		x=read();
		if(x>c/2)
		{
			int F=0;
			for(int i=n;i>=tr;i--)
				if(a[i]<x)
				{
					a[i]=x,F=i;break;
				}
			if(!F)tr--,F=tr,a[tr]=x;
			printf("%d\n",F);fflush(stdout);
		}
		else 
		{
			int F=0;
			for(int i=1;i<=tl;i++)
				if(a[i]>x)
				{
					a[i]=x,F=i;break;
				}
			if(!F)tl++,F=tl,a[tl]=x;
			printf("%d\n",F);fflush(stdout);
		}
	//	cout<<tl<<" "<<tr<<endl;
		if(tl==tr-1)break;
	}
	return 0;
}