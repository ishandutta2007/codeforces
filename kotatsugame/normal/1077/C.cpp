#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >A(N);
	long long S=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i].first);
		A[i].second=i;
		S+=A[i].first;
	}
	sort(A.begin(),A.end());
	vector<int>ans;
	if((S-A.back().first)%2==0&&(S-A.back().first)/2==A[N-2].first)ans.push_back(A.back().second);
	for(int i=0;i<N-1;i++)
	{
		long long T=S-A[i].first;
		if(T%2==0&&T/2==A[N-1].first)ans.push_back(A[i].second);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i]+1,i+1==ans.size()?10:32);
}