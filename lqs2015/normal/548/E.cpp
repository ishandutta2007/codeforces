#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long n,q,x,cur[555555],a[222222],mx[555555],res,cnt,mult,sz;
bool placed[555555],f;
vector<long long> p;
int main()
{
	for (int i=2;i<=500000;i++)
	{
		if (!mx[i])
		{
			for (int j=i;j<=500000;j+=i)
			mx[j]=i;
		}
	}
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(q--)
	{
		scanf("%d",&x);
		placed[x]=!placed[x];
		f=placed[x];
		x=a[x];
		p.clear();
		while(x>1)
		{
			long long pr=mx[x];
			if (p.empty() || pr!=p.back()) p.push_back(pr);
			x/=pr; 
		}
		if (!f) sz--;
		if (f) res+=sz;
		else res-=sz;
		if (f) sz++;
		for (int mask=1;mask<(1<<p.size());mask++)
		{
			cnt=mult=1;
			for (int i=0;i<p.size();i++)
			{
				if (mask&(1<<i))
				{
					cnt*=-1;
					mult*=p[i];
				}
			}
			if (!f) cur[mult]--;
			if (f^(cnt==1)) res-=cur[mult];
			else res+=cur[mult];
			if (f) cur[mult]++;
		}
		printf("%I64d\n",res);
	}
	return 0;
}