#include<cstdio>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int N,M,Q;
int TON[2<<17],TOM[2<<17];
bool Nb[2<<17],aM[2<<17];
main()
{
	scanf("%d%d%d",&N,&M,&Q);
	vector<pair<int,int> >S;S.reserve(Q);
	for(int i=0;i<Q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==N||b==M)
		{
			if(a==N)Nb[b]=true;
			if(b==M)aM[a]=true;
		}
		else S.push_back(make_pair(a,b));
	}
	for(int b=M-1;b>=1;b--)
	{
		TON[b]=TON[min(b+N+Nb[b],M)]+1;
	}
	for(int a=N-1;a>=1;a--)
	{
		TOM[a]=TOM[min(a+M+aM[a],N)]+1;
	}
	sort(S.begin(),S.end());
	vector<pair<int,int> >now,nxt;
	now.push_back(make_pair(1,1));
	int ans=1e9;
	int turn=0;
	for(;++turn<ans;)
	{
		nxt.clear();
		for(pair<int,int>p:now)
		{
			int a=p.first,b=p.second;
			auto it=lower_bound(S.begin(),S.end(),make_pair(a,b));
			int f=it!=S.end()&&*it==make_pair(a,b);
			if(a+b+f<N)
			{
				nxt.push_back(make_pair(a+b+f,b));
			}
			else
			{
				ans=min(ans,turn+TON[b]);
			}
			if(a+b+f<M)
			{
				nxt.push_back(make_pair(a,a+b+f));
			}
			else
			{
				ans=min(ans,turn+TOM[a]);
			}
		}
		sort(nxt.begin(),nxt.end());
		nxt.erase(unique(nxt.begin(),nxt.end()),nxt.end());
		sort(nxt.begin(),nxt.end(),[](const pair<int,int>&lhs,const pair<int,int>&rhs)
		{
			return lhs.first+lhs.second>rhs.first+rhs.second;
		});
		if(nxt.size()>=100000)nxt.resize(10000);
		now.swap(nxt);
	}
	printf("%d\n",ans);
}