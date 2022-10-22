#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
mt19937 ran(chrono::steady_clock::now().time_since_epoch().count());
map<int,int>ma;
int dy[600005][41];
long long f[300005][41];
int a[300005];
int n;
void insert(int k,long long x,int tid)
{
	while(k<=n)
	{
		f[k][tid]+=x;
		k+=((k)&(-k));
	}
}
long long query(int k,int tid)
{
	long long ans=0;
	while(k>=1)
	{
		ans+=f[k][tid];
		k-=((k)&(-k));
	}
	return ans;
}
int cnt;
int main()
{
	int q,l,r,opt,x,y,k;
	n=read();
	q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(ma[a[i]]==0)
		{
			ma[a[i]]=++cnt;
			for(int j=1;j<=40;j++)dy[cnt][j]=ran();
		}
		int now=ma[a[i]];
		for(int j=1;j<=40;j++)insert(i,dy[now][j],j);
	}
	for(int i=1;i<=q;i++)
	{
		opt=read();
		if(opt==1)
		{
			x=read();
			y=read();
			int sth=ma[a[x]];
			for(int j=1;j<=40;j++)insert(x,-dy[sth][j],j);
			a[x]=y;
			if(ma[y]==0)
			{
				ma[y]=++cnt;
				for(int j=1;j<=40;j++)dy[cnt][j]=ran();
			}
			sth=ma[y];
			for(int j=1;j<=40;j++)insert(x,dy[sth][j],j);
		}
		else
		{
			l=read();
			r=read();
			k=read();
			if(k==1)
			{
				printf("YES\n");
				continue;
			}
			bool flag=true;
			for(int j=1;j<=40;j++)
			{
				if((query(r,j)-query(l-1,j))%k!=0)
				{
					flag=false;
					break;
				}
			}
			if(flag==true)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}