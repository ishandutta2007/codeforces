#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int N,C[1010];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&C[i]);
		if(i%2==1)C[i]=-C[i];
	}
	long long ans=0;
	stack<pair<long long,int> >S;
	long long cumsum=0;
	for(int i=0;i<N;i++)
	{
		if(C[i]>0)cumsum+=C[i];
		else
		{
			if(cumsum+C[i]>=0)
			{
				ans+=-C[i];
				cumsum+=C[i];
				while(!S.empty()&&S.top().first>cumsum)
				{
					ans+=S.top().second;
					S.pop();
				}
				if(!S.empty()&&S.top().first==cumsum)
				{
					ans+=S.top().second;
					S.top().second++;
				}
				else
				{
					S.push(make_pair(cumsum,1));
				}
			}
			else
			{
				ans+=cumsum;
				while(!S.empty())
				{
					ans+=S.top().second;
					S.pop();
				}
				cumsum=0;
			}
		}
	}
	printf("%lld\n",ans);
}