#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100010;
const int INF=2000000010;

int n,v;
pair<int,int> a[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d%d",&a[i].first,&a[i].second);
	cin>>v;
	for (int i=1;i<=n;++i)
	{
		int x=a[i].first,t=a[i].second;
		a[i].first=v*t-x;
		a[i].second=v*t+x;
	}
}

int F[MaxN];

int solve_1()
{
	a[++n]=make_pair(0,0);
	sort(a+1,a+n+1);
	int ans=0;
	int flag=0;
	for (int i=1;i<=n;++i)
	{
		if (a[i].first==0&&a[i].second==0)
		{
			flag=1;
			F[0]=0;
			continue;
		}
		if (!flag) continue;
		if (a[i].second<0) continue;
		if (F[ans]<=a[i].second)
			F[++ans]=a[i].second;
		else
			F[upper_bound(F,F+ans+1,a[i].second)-F]=a[i].second;
	}
	return ans;
}

int solve_2()
{
	sort(a+1,a+n+1);
	int ans=0;
	F[0]=-INF;
	for (int i=1;i<=n;++i)
	{
		if (F[ans]<=a[i].second)
			F[++ans]=a[i].second;
		else
			F[upper_bound(F,F+ans+1,a[i].second)-F]=a[i].second;
	}
	return ans;
}

void work()
{
	int ans2=solve_2();
	int ans1=solve_1();
	cout<<ans1<<" "<<ans2<<endl;
}

int main()
{
	init();
	work();
	return 0;
}