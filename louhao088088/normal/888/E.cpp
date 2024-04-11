#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
} 
int n,m,a[105],b[(1<<18)+1],c[(1<<18)+1],ha,cnt1=0,cnt2=0,ans=0;
void dfs1(int x,int num)
{
	if(x==ha+1)
	{
		b[++cnt1]=num;return;
	}
	
	dfs1(x+1,num);dfs1(x+1,(num+a[x])%m);
}
void dfs2(int x,int num)
{
	if(x==n+1)
	{
		c[++cnt2]=num;return;
	}
	dfs2(x+1,num);
	dfs2(x+1,(num+a[x])%m);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ha=n/2;//cout<<ha<<endl;
	dfs1(1,0);dfs2(ha+1,0);
	sort(b+1,b+cnt1+1);sort(c+1,c+cnt2+1);
	int l=1,r=cnt2;
	while(l<=cnt1)
	{
		while(b[l]+c[r]>=m)r--;//cout<<a[l]+b[r]<<endl;
		ans=max(ans,b[l]+c[r]);l++;
	}
	cout<<max(ans,(b[cnt1]+c[cnt2])%m);
	return 0;
}