#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int n,m,k;
int pow[12];
vector<int> v[12];
long long F[60010];

void init()
{
	cin>>n>>m>>k;
	for (int i=pow[0]=1;i<=n;++i)
		pow[i]=pow[i-1]*3;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		--x;
		--y;
		v[x].push_back(y);
		v[y].push_back(x);
		F[pow[x]+pow[y]]=2;
	}
}

void work()
{
	long long ans=0;
	for (int s=1;s<pow[n];++s)
	{
		if (!F[s]) continue;
		int p[12];
		int t=s;
		int A=0,B=0;
		for (int i=0;i<n;++i)
		{
			p[i]=t%3;
			t/=3;
			if (p[i]==1) ++A;
			if (p[i]==2) ++B;
		}
		F[s]/=A;
		if (A+B==n&&A==k) ans+=F[s];
		for (int i=0;i<n;++i) if (p[i])
			for (int j=0;j<v[i].size();++j) if (!p[v[i][j]])
			{
				int x=v[i][j];
				int t=s+pow[x];
				if (p[i]==1) t+=pow[i];
				F[t]+=F[s];
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