#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,A[2000],B[2000];
long long SA,SB;
long long V;
vector<pair<int,int> >ans;
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		SA+=A[i];
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d",&B[i]);
		SB+=B[i];
	}
	V=abs(SA-SB);
	{//1
		vector<pair<long long,int> >Bs(M);
		for(int i=0;i<M;i++)Bs[i]=make_pair(2*B[i],i);
		sort(Bs.begin(),Bs.end());
		for(int x=0;x<N;x++)
		{
			long long d=SA-SB-2*A[x];
			auto it=lower_bound(Bs.begin(),Bs.end(),make_pair(-d,0));
			if(it!=Bs.end())
			{
				long long now=d+it->first;
				if(abs(now)<V)
				{
					V=abs(now);
					ans.clear();
					ans.push_back(make_pair(x,it->second));
				}
			}
			if(it!=Bs.begin())
			{
				it--;
				long long now=d+it->first;
				if(abs(now)<V)
				{
					V=abs(now);
					ans.clear();
					ans.push_back(make_pair(x,it->second));
				}
			}
		}
	}
	{//2
		vector<pair<long long,pair<int,int> > >Bs;Bs.reserve(M*(M-1)/2);
		for(int i=0;i<M;i++)for(int j=i+1;j<M;j++)
		{
			Bs.push_back(make_pair(2LL*(B[i]+B[j]),make_pair(i,j)));
		}
		sort(Bs.begin(),Bs.end());
		for(int x1=0;x1<N;x1++)for(int x2=x1+1;x2<N;x2++)
		{
			long long d=SA-SB;
			d-=2*A[x1];
			d-=2*A[x2];
			auto it=lower_bound(Bs.begin(),Bs.end(),make_pair(-d,make_pair(0,0)));
			if(it!=Bs.end())
			{
				long long now=d+it->first;
				if(abs(now)<V)
				{
					V=abs(now);
					ans.clear();
					ans.push_back(make_pair(x1,it->second.first));
					ans.push_back(make_pair(x2,it->second.second));
				}
			}
			if(it!=Bs.begin())
			{
				it--;
				long long now=d+it->first;
				if(abs(now)<V)
				{
					V=abs(now);
					ans.clear();
					ans.push_back(make_pair(x1,it->second.first));
					ans.push_back(make_pair(x2,it->second.second));
				}
			}
		}
	}
	printf("%lld\n",V);
	printf("%d\n",ans.size());
	for(pair<int,int>p:ans)printf("%d %d\n",p.first+1,p.second+1);
}