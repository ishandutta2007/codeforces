#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int M,N,T,A,B;
main()
{
	scanf("%d",&M);
	for(;M--;)
	{
		scanf("%d%d%d%d",&N,&T,&A,&B);
		vector<pair<int,int> >X(N);
		int pa=0,pb=0;
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);X[i].second=a;
			if(a==0)pa++;
			else pb++;
		}
		for(int i=0;i<N;i++)
		{
			int t;scanf("%d",&t);X[i].first=t;
		}
		X.push_back(make_pair(T+1,0));
		sort(X.begin(),X.end());
		long long cumsum=0;
		int ret=0;
		for(int i=0;i<=N;)
		{
			int ti=X[i].first-1;
			if(ti>=cumsum)
			{
				int ans=i;
				int lest=ti-cumsum;
				if(lest/A<=pa)ans+=lest/A;
				else
				{
					ans+=pa;
					lest-=pa*A;
					if(lest/B<=pb)ans+=lest/B;
					else ans+=pb;
				}
				if(ret<ans)ret=ans;
			}
			int j=i;
			while(i<=N&&X[j].first==X[i].first)
			{
				if(X[i].second==0)
				{
					cumsum+=A;
					pa--;
				}
				else
				{
					cumsum+=B;
					pb--;
				}
				i++;
			}
		}
		printf("%d\n",ret);
	}
}