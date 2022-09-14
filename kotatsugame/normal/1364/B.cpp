#include<cstdio>
#include<vector>
using namespace std;
int T,N;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		vector<int>ans;
		ans.push_back(A[0]);
		int now;
		if(A[0]<A[1])now=1;
		else now=-1;
		for(int i=2;i<N;i++)
		{
			if(now==1)
			{
				if(A[i-1]>A[i])
				{
					ans.push_back(A[i-1]);
					now=-1;
				}
			}
			else
			{
				if(A[i-1]<A[i])
				{
					ans.push_back(A[i-1]);
					now=1;
				}
			}
		}
		ans.push_back(A[N-1]);
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
	}
}