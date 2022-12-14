#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m,f[55];
map<long long,long long> mp;
bool b[55][55],ans[55];
char c;
int main()
{
	cin>>n>>m;
	for (long long i=1;i<=n;i++)
	{
		getchar();
		for (long long j=1;j<=m;j++)
		{
			c=getchar();
			if (c=='#') b[i][j]=1;
			else b[i][j]=0;
			f[i]=f[i]*2+b[i][j];
		}
	}
	for (long long i=1;i<=n;i++)
	{
		if (mp[f[i]]) continue;
		mp[f[i]]=1;
		for (long long j=1;j<=m;j++)
		{
			if (!b[i][j]) continue;
			if (ans[j]) 
			{
				cout<<"No"<<endl;
				return 0;
			}
			ans[j]=1;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}