#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int N;
int cnt[(2<<17)+5];
long long sum[(2<<17)+10];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a;scanf("%d",&a);
		cnt[a]++;
	}
	sum[0]=0;
	for(int i=0;i<2<<17;i++)
	{
		sum[i+1]=sum[i]+cnt[i];
	}
	vector<pair<int,int> >E;
	int L=0;
	while(L<2<<17)
	{
		while(cnt[L]<2&&L<2<<17)L++;
		if(L==(2<<17))break;
		int R=L;
		while(R<2<<17&&cnt[R]>=2)R++;
		E.push_back(make_pair(L,R-1));
		L=R;
	}
	pair<int,int>ansLR;
	long long mi=-9e18;
	for(int i=0;i<E.size();i++)
	{
		int L=E[i].first,R=E[i].second;
		long long now=sum[R+1]-sum[L];
		if(L>0&&cnt[L-1]>0)
		{
			now+=cnt[L-1];
		}
		if(cnt[R+1]>0)now+=cnt[R+1];
		if(mi<now)
		{
			mi=now;
			ansLR=E[i];
		}
	}
	if(mi<2)
	{
		int g;
		for(int i=0;i<2<<17;i++)
		{
			if(cnt[i]&&cnt[i+1])
			{
				printf("2\n%d %d\n",i,i+1);
				return 0;
			}
			else if(cnt[i])
			{
				mi=1;
				g=i;
			}
		}
		printf("1\n%d\n",g);
		return 0;
	}
	vector<int>ans;
	L=ansLR.first;
	int R=ansLR.second;
	for(int i=L>0?L-1:L;i<=R+1;i++)
	{
		for(int j=1;j<cnt[i];j++)ans.push_back(i);
	}
	for(int i=R+1;i>=(L>0?L-1:L);i--)
	{
		if(cnt[i])ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
}