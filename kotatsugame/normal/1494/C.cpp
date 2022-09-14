#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,M;
int calc(vector<int>A,vector<int>B)
{
	vector<int>cnt(A.size()+1);
	cnt[A.size()]=0;
	{
		int bi=B.size();
		for(int i=A.size();i--;)
		{
			cnt[i]=cnt[i+1];
			while(bi>0&&B[bi-1]>A[i])bi--;
			if(bi>0&&B[bi-1]==A[i])cnt[i]++;
		}
	}
	int ans=0,ai=0,bi=0;
	for(int i=0;i<B.size();i++)
	{
		while(ai<A.size()&&A[ai]<=B[i]+ai)ai++;
		while(bi<B.size()&&B[bi]<B[i]+ai)bi++;
		//printf("%d+%d ",bi-i,cnt[bi]);
		ans=max(ans,bi-i+cnt[ai]);
	}
	//printf("%d\n",ans);
	return ans;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<int>LA,RA,LB,RB;
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			if(a<0)LA.push_back(-a);
			else RA.push_back(a);
		}
		for(int i=0;i<M;i++)
		{
			int b;scanf("%d",&b);
			if(b<0)LB.push_back(-b);
			else RB.push_back(b);
		}
		reverse(LA.begin(),LA.end());
		reverse(LB.begin(),LB.end());
		printf("%d\n",calc(LA,LB)+calc(RA,RB));
	}
}