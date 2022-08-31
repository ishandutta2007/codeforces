#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100010;

int n,k;
long long a[MaxN];
long long s[MaxN];

void init()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		a[i]=x;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
}

void work()
{
	int many=0;
	long long get;
	for (int i=1;i<=n;++i)
	{
		int L=1,R=i;
		while (L<=R)
		{
			int mid=(L+R)>>1;
			long long sx=a[i]*mid-(s[i]-s[i-mid]);
			if (sx<=k)
			{
				if (mid>many)
				{
					many=mid;
					get=a[i];
				}
				L=mid+1;
			}
			else
				R=mid-1;
		}
	}
	cout<<many<<" "<<get<<endl;
}

int main()
{
	init();
	work();
	return 0;
}