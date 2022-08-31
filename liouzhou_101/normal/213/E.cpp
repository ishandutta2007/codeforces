#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int MaxN=200010;

int n,m;
int a[MaxN],b[MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		a[x]=i;
	}
	for (int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		b[x]=i;
	}
}

int pre[MaxN],suf[MaxN];
int p[MaxN];

bool check(int *a,int i,int j)
{
	if (pre[j])
		if (a[i-j+pre[j]]>a[i])
			return false;
	if (suf[j])
		if (a[i-j+suf[j]]<a[i])
			return false;
	return true;
}

set<pair<int,int> > H;

void work()
{
	H.insert(make_pair(0,0));
	H.insert(make_pair(MaxN,0));
	for (int i=1;i<=n;++i)
	{
		set<pair<int,int> >::iterator x,y;
		x=y=H.insert(make_pair(a[i],i)).first;
		--x;
		++y;
		pre[i]=x->second;
		suf[i]=y->second;
	}
	for (int i=2;i<=n;++i)
	{
		int j=p[i-1];
		while (j)
		{
			if (check(a,i,j+1)) break;
			j=p[j];
		}
		p[i]=j+(check(a,i,j+1));
	}
	int ans=0;
	for (int i=1,j=0;i<=m;++i)
	{
		while (j)
		{
			if (check(b,i,j+1)) break;
			j=p[j];
		}
		j+=check(b,i,j+1);
		if (j==n)
		{
			++ans;
			j=p[j];
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