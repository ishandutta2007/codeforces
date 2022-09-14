#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int X[1000],Y[1000];
main()
{
	scanf("%d",&N);
	int flag=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		if((X[i]+Y[i])%2==0)flag|=1;
		else flag|=2;
	}
	vector<int>ans;
	if(flag==3)
	{
		for(int i=0;i<N;i++)
		{
			if((X[i]+Y[i])%2==0)ans.push_back(i);
		}
	}
	else
	{
		for(int j=1;;j++)
		{
			vector<pair<pair<int,int>,int> >Z(N);
			int mod=1<<j;
			for(int i=0;i<N;i++)
			{
				pair<int,int>p;
				p.first=(X[i]%mod+mod)%mod;
				p.second=(Y[i]%mod+mod)%mod;
				Z[i]=make_pair(p,i);
			}
			sort(Z.begin(),Z.end());
			if(Z[0].first!=Z[N-1].first)
			{
				int cnt=0;
				for(int i=0;i<N;i++)
				{
					if(i>0&&Z[i-1].first!=Z[i].first)cnt++;
					if(cnt==0||cnt==3)
					{
						ans.push_back(Z[i].second);
					}
				}
				break;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i]+1,i+1==ans.size()?'\n':' ');
}