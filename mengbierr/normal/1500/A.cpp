#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
pii p[5000005];
int vis[5000005],ans[5],a[5000005];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int num1=0,num2=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[a[i]]) vis[a[i]]=i;
		else
		{
			if(!num1) num1=a[i];
			else if(!num2&&a[i]!=num1) num2=a[i];
		}
	}
	if(num1&&num2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==num1)
			{
				if(!ans[1]) ans[1]=i;
				else ans[3]=i; 
			}
			else if(a[i]==num2)
			{
				if(!ans[2]) ans[2]=i;
				else ans[4]=i;
			}
		}
		cout<<"YES"<<endl<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4];
		return 0;
	}
	else if(num1)
	{
		int cou=0;
		for(int i=1;i<=n;i++)
		{
			if(num1==a[i]) cou++;
		}
		if(cou>=4)
		{
			puts("YES");
			//cout<<">>>";
			int tmp=0;
			for(int i=1;i<=n;i++)
			{
				if(num1==a[i])
				{
					cout<<i<<" ";
					tmp++;
					if(tmp==4) return 0;
				}
			}
		}
	}
	bool ok=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(i==j) continue;
			pii tmp=p[a[i]+a[j]];
			if(!p[a[i]+a[j]].first) p[a[i]+a[j]].first=i,p[a[i]+a[j]].second=j;
			else
			{
				if(tmp.first==i||tmp.second==j||tmp.first==j||tmp.second==i) continue;
				puts("YES");
				cout<<i<<" "<<j<<" "<<tmp.first<<" "<<tmp.second;
				return 0;
			}
		}
	}
	puts("NO");
}