#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define N 1000010
#define mod 1000000007
using namespace std;
vector<int>v[N];
ll n,f[N],ans;
int a[N],i,j;
int main()
{
	cin>>n;f[0]=1;for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=1000000;i++) for (j=i;j<=1000000;j+=i) v[j].push_back(i);
	for (i=1;i<=n;i++)
	{
		for (j=v[a[i]].size()-1;j>=0;j--)
		{
			if (v[a[i]][j]<=i)(f[v[a[i]][j]]+=f[v[a[i]][j]-1])%=mod;
		}
	} 
	for (i=1;i<=n;i++) (ans+=f[i])%=mod;cout<<ans;
}