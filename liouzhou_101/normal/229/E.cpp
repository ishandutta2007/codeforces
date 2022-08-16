#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

const int MaxN=1010;
const long double INF=1e40;
const long double ZERO=1e-16;

int n,m;
vector<int> v[MaxN],w;
long double C[MaxN][MaxN];
int have[MaxN],must[MaxN];
long double F[MaxN][MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int k;
		cin>>k;
		while (k--)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
			w.push_back(x);
		}
		sort(v[i].begin(),v[i].end());
	}
	sort(w.begin(),w.end());
	for (int i=0;i<=w.size();++i)
		C[i][0]=1;
	for (int i=1;i<=w.size();++i)
		for (int j=1;j<=i;++j)
			C[i][j]=min(INF,C[i-1][j-1]+C[i-1][j]);
}

void work()
{
	int limit=w[w.size()-n];
	int deal=0,need=0;
	for (int i=1;i<=m;++i)
	{
		for (int j=0;j<v[i].size();++j)
		{
			if (v[i][j]==limit) have[i]++;
			if (v[i][j]>limit) must[i]++;
		}
		deal+=have[i];
		need+=must[i];
	}
	long double ans=1;
	F[0][0]=1;
	int cut=0;
	for (int i=1;i<=m;++i)
	{
		if (!have[i])
		{
			ans/=C[v[i].size()][must[i]];
			for (int j=0;j<=deal;++j)
				F[i][j]=F[i-1][j];
			continue;
		}
		++cut;
		for (int j=0;j<=deal;++j)
		{
			F[i][j]+=F[i-1][j]/C[v[i].size()][must[i]];
			F[i][j+1]+=F[i-1][j]/C[v[i].size()][must[i]+1];
		}
	}
	cout<<setprecision(15)<<fixed<<F[m][n-need]/C[cut][n-need]*ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}