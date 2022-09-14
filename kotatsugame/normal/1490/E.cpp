#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
long long S[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<pair<int,int> >A(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i].first);
			A[i].second=i;
		}
		sort(A.begin(),A.end());
		for(int i=1;i<=N;i++)S[i]=S[i-1]+A[i-1].first;
		vector<int>ans;
		ans.push_back(A[N-1].second);
		int mx=A[N-1].first;
		for(int i=N-1;i--;)
		{
			if(mx<=S[i+1])
			{
				ans.push_back(A[i].second);
				mx=A[i].first;
			}
		}
		sort(ans.begin(),ans.end());
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();i++)printf("%d%c",ans[i]+1,i+1==ans.size()?10:32);
	}
}