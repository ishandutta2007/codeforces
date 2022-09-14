#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,L,R;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&L,&R);
		map<int,int>mp;
		for(int i=0;i<N;i++)
		{
			int C;scanf("%d",&C);
			if(i<L)mp[C]++;
			else mp[C]--;
		}
		int l=0,r=0;
		vector<int>lp,rp;
		for(pair<int,int>p:mp)
		{
			if(p.second>0)
			{
				l+=p.second;
				lp.push_back(p.second);
			}
			else if(p.second<0)
			{
				r-=p.second;
				rp.push_back(-p.second);
			}
		}
		int ans=abs(l-r)/2+(l+r)/2;
		if(l>r)
		{
			int t=(l-r)/2;
			for(int lu:lp)
			{
				int x=lu/2;
				if(t>x)ans-=x,t-=x;
				else ans-=t,t=0;
			}
		}
		else
		{
			int t=(r-l)/2;
			for(int ru:rp)
			{
				int x=ru/2;
				if(t>x)ans-=x,t-=x;
				else ans-=t,t=0;
			}
		}
		printf("%d\n",ans);
	}
}