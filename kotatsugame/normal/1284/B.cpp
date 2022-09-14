#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int L[1<<17];
vector<int>s[1<<17];
vector<int>mi,ma;
main()
{
	scanf("%d",&N);
	long long ans=N;
	ans*=N;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&L[i]);
		for(int j=0;j<L[i];j++)
		{
			int a;scanf("%d",&a);
			s[i].push_back(a);
		}
		bool now=false;
		for(int j=1;j<L[i];j++)
		{
			if(s[i][j-1]<s[i][j])
			{
				now=true;
				break;
			}
		}
		if(now)
		{
		}
		else
		{
			int MI=s[i][0],MA=s[i][0];
			for(int j=1;j<L[i];j++)
			{
				MI=min(MI,s[i][j]);
				MA=max(MA,s[i][j]);
			}
			mi.push_back(MI);
			ma.push_back(MA);
		}
	}
	sort(mi.begin(),mi.end());
	sort(ma.begin(),ma.end());
	long long X=mi.size();
	ans-=X*X;
	int id=ma.size();
	for(int i=mi.size();i--;)
	{
		while(id>0&&ma[id-1]>mi[i])id--;
		ans+=ma.size()-id;
	}
	printf("%lld\n",ans);
}