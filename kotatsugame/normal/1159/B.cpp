#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int A[3<<17];
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >X(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		X[i]=make_pair(A[i],i);
	}
	sort(X.begin(),X.end());
	reverse(X.begin(),X.end());
	int ans=2e9;
	int mn=N-1,mx=0;
	for(pair<int,int>p:X)
	{
		int id=p.second;
		if(mn<id)
		{
			ans=min(ans,p.first/(id-mn));
		}
		else mn=id;
		if(mx>id)
		{
			ans=min(ans,p.first/(mx-id));
		}
		else mx=id;
	}
	printf("%d\n",ans);
}