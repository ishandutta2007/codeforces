#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,K;
pair<int,int>LR[2020];
int L[2020],R[2020];
int cross(int k,int id)
{
	int l=LR[id].first,r=LR[id].second;
	int x=k,y=k+K;
	return max(0,min(y,r)-max(x,l));
}
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		LR[i]=make_pair(l-1,r);
	}
	sort(LR,LR+M,[](pair<int,int>a,pair<int,int>b){
		int X=a.first+a.second,Y=b.first+b.second;
		return X<Y;
	});
	int ans=0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<=N-K;j++)
		{
			R[j]+=cross(j,i);
			if(ans<R[j])ans=R[j];
		}
	}
	int ml=0;
	for(int i=0;i<M;i++)
	{
		int mr=0;
		for(int j=0;j<=N-K;j++)
		{
			int t=cross(j,i);
			L[j]+=t;
			if(ml<L[j])ml=L[j];
			R[j]-=t;
			if(mr<R[j])mr=R[j];
		}
		if(ans<ml+mr)ans=ml+mr;
	}
	printf("%d\n",ans);
}