#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int Q,N,A[3<<17];
int L[3<<17],R[3<<17];
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			L[i]=R[i]=-1;
		}
		for(int i=0;i<N;i++)
		{
			scanf("%d",A+i);
			A[i]-=1;
			if(L[A[i]]<0)L[A[i]]=i;
			R[A[i]]=i;
		}
		vector<pair<int,int> >B;
		for(int i=0;i<N;i++)
		{
			if(R[i]>=0)
			{
				B.push_back(make_pair(L[i],R[i]));
			}
		}
		int ans=1,now=1;
		for(int i=1;i<B.size();i++)
		{
			if(B[i-1].second<B[i].first)
			{
				now+=1;
			}
			else now=1;
			ans=max(ans,now);
		}
		printf("%d\n",(int)B.size()-ans);
	}
}