#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int N,M;
vector<pair<int,int> >E;
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		a--,b--;
		E.push_back(minmax(a,b));
	}
	sort(E.begin(),E.end());
	vector<int>div;
	for(int i=1;i*i<=N;i++)
	{
		if(N%i==0)
		{
			div.push_back(i);
			if(i!=N/i)div.push_back(N/i);
		}
	}
	for(int i=0;i<div.size();i++)
	{
		int d=div[i];
		if(d==N)continue;
		vector<pair<int,int> >F(M);
		for(int j=0;j<M;j++)
		{
			F[j]=minmax((E[j].first+d)%N,(E[j].second+d)%N);
		}
		sort(F.begin(),F.end());
		if(E==F)
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}