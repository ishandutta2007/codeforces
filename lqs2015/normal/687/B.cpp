#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1000;
int n,k,prime[1111111],ct,cnt[1111111],yy[1111111],mx[1111111],x;
bool f[1111111];
vector<int> v;
void split(int x)
{
	v.clear();
	for (int i=1;i<=ct;i++)
	{
		if (x%prime[i]) continue;
		v.push_back(prime[i]);
		while(x%prime[i]==0)
		{
			cnt[prime[i]]++;
			x/=prime[i];
		} 
	}
	if (x!=1) 
	{
		cnt[x]=1;
		v.push_back(x); 
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			for (int j=i+i;j<=maxn;j+=i) f[j]=1;
		}
	}
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i]) prime[++ct]=i;
	}
	split(k);
	for (int i=2;i<=1000000;i++) 
	{
		yy[i]=cnt[i];
		cnt[i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		split(x);
		for (int j=0;j<v.size();j++)
		{
			mx[v[j]]=max(mx[v[j]],cnt[v[j]]);
			cnt[v[j]]=0;
		}
	}
	for (int i=2;i<=1000000;i++) 
	{
		if (mx[i]<yy[i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}