#include<iostream>
#include<vector>
using namespace std;
main()
{
	int L,R;
	scanf("%d%d",&L,&R);
	int D=R-L+1;
	vector<pair<pair<int,int>,int> >E;
	int n=0;
	for(;D>>n;n++)
	{
		E.push_back(make_pair(make_pair(0,n+1),1));
		if(n>0)
		{
			for(int j=n;j>0;j--)E.push_back(make_pair(make_pair(n+1,j),1<<n-1));
		}
	}
	n--;
	D-=1<<n;
	int T=1<<n;
	n+=2;
	if(D>0)
	{
		E.push_back(make_pair(make_pair(0,n),1));
		T--;
		for(int k=0;k<n-2;k++)
		{
			if(D>>k&1)
			{
				E.push_back(make_pair(make_pair(n,k+2),T));
			}
			else
			{
				T-=1<<k;
			}
		}
		n++;
	}
	for(pair<pair<int,int>,int>&e:E)
	{
		if(e.first.first!=0)e.first.first=n-e.first.first;
		if(e.first.second!=0)e.first.second=n-e.first.second;
	}
	if(L>1)
	{
		for(pair<pair<int,int>,int>&e:E)
		{
			e.first.first++;
			e.first.second++;
		}
		E.push_back(make_pair(make_pair(0,1),L-1));
		n++;
	}
	puts("YES");
	printf("%d %d\n",n,(int)E.size());
	for(pair<pair<int,int>,int>e:E)
	{
		printf("%d %d %d\n",e.first.first+1,e.first.second+1,e.second);
	}
}