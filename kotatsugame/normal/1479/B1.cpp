#include<cstdio>
#include<vector>
using namespace std;
int N;
int A[1<<17];
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >X;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		if(X.empty()||X.back().first!=A[i])
		{
			X.push_back(make_pair(A[i],1));
		}
		else X.back().second++;
	}
	int p2=-1,p1=-1;
	int ans=0;
	bool fn=false;
	for(pair<int,int>p:X)
	{
		ans++;
		if(p.second==1)
		{
			if(p1!=p2&&p2!=p.first)fn=true;
			p1=p.first;
		}
		else
		{
			if(p.first!=p2)
			{
				ans++;
			}
			else
			{
				if(fn)ans++;
			}
			fn=false;
			p2=p1=p.first;
		}
	}
	printf("%d\n",ans);
}