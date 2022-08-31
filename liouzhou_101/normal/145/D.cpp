#include<cstdio>
#include<iostream>
#include<set>

using namespace std;

const int MaxN=100010;

int n,v[MaxN];
int m,p[MaxN];
int next[MaxN];

bool check(int x)
{
	for (;x;x/=10)
		if (x%10!=4&&x%10!=7) return false;
	return true;
}

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&v[i]);
		if (check(v[i])) p[++m]=i;
	}
	for (int i=1;i<=m;++i)
	{
		next[i]=MaxN;
		for (int j=i+1;j<=m;++j)
			if (v[p[i]]==v[p[j]])
			{
				next[i]=j;
				break;
			}
	}
}

long long ans;

void work()
{
	for (long long i=1;i<=n;++i)
		ans+=i*(i+1)/2*(n-i);
	for (int i=1;i<=m;++i)
	{
		set<int> H;
		H.insert(p[i]);
		H.insert(n+1);
		long long now=0;
		for (int j=i;j>=1;--j)
		{
			if (next[j]>i)
				for (int k=next[j];k<=m;k=next[k])
				{
					set<int>::iterator x,y;
					x=y=H.insert(p[k]).first;
					--x;
					++y;
					if (*x==p[i])
					{
						now+=(long long)(p[i+1]-p[i])*(p[i+1]-p[i]+1)/2*(*y-p[k]);
						now+=(long long)(p[i+1]-p[i])*(p[k]-p[i+1])*(*y-p[k]);
					}
					else
					{
						now+=(long long)(p[i+1]-p[i])*(p[k]-*x)*(*y-p[k]);
					}
				}
			ans-=now*(p[j]-p[j-1]);
		}
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}