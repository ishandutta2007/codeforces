#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
struct data
{
	int l;
	int r;
	int w;
	int minn;
}a[200005];
vector<data> v[200005];
int cmp(const data &x,const data &y)
{
	return x.l<y.l;
}
int n,ans=2100000000,k;
int find(int now,int x)
{
	int l=0,r=v[now].size()-1,temp=2100000000;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(v[now][mid].l>=x)
		{
			r=mid-1;
			temp=min(temp,v[now][mid].minn);
		}
		else
		{
			l=mid+1;
		}
	}
	return temp;
}
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;i++)
	{
		a[i].l=read(),a[i].r=read(),a[i].w=read();
		v[a[i].r-a[i].l+1].push_back(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
	}
	for(int i=1;i<=200000;i++)
	{
		int x=v[i].size();
		//cout<<x<<" ";
		if(x)
		{
			v[i][x-1].minn=v[i][x-1].w;
			//cout<<"ok";
		}
		for(int j=x-2;j>=0;j--)
		{
			v[i][j].minn=min(v[i][j+1].minn,v[i][j].w);
		}
		//cout<<"ok";
		///if(x)
		//cout<<v[i][0].minn<<" ";
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].r-a[i].l+1>=k) continue;
		int x=find(k-(a[i].r-a[i].l+1),a[i].r+1);
		//cout<<i<<" "<<a[i].w<<" "<<x<<endl;
		if(x!=2100000000)
		ans=min(ans,a[i].w+x);
	}
	if(ans!=2100000000) cout<<ans;
	else cout<<"-1";
}