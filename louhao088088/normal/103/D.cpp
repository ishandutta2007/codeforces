#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=3e5+5;
int n,m,v[maxn],t,d=0;
long long s[550][550],ans[maxn];
struct node
{
	int x,y,id;
}a[maxn];
bool cmp(node a,node b){return a.x<b.x;}
char c=0;
signed main()
{
	n=read();t=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		v[i]=read();
		for(int j=1;j<=t;j++)
			s[j][i%j]+=v[i];
	}m=read();
	for(int i=1;i<=m;i++)
		a[i].x=read(),a[i].y=read(),a[i].id=i;
	sort(a+1,a+m+1,cmp);d=0;
	for(int i=1;i<=m;i++)
	{
		//cout<<d<<endl;
		if(a[i].y<=t)
		{
			while(a[i].x>d)
			{
				for(int j=1;j<=t;j++)s[j][d%j]-=v[d];d++;
			}
			ans[a[i].id]=s[a[i].y][a[i].x%a[i].y];
		}
		else
		{
			for(int j=a[i].x;j<=n;j+=a[i].y)
				ans[a[i].id]+=v[j];
		}
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}