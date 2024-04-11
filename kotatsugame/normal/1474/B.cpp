#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,D;
bool isp[1<<17];
vector<int>ps;
main()
{
	for(int i=2;i<1<<17;i++)if(!isp[i])
	{
		ps.push_back(i);
		for(int j=i+i;j<1<<17;j+=i)isp[j]=true;
	}
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&D);
		int p=*lower_bound(ps.begin(),ps.end(),D+1);
		int q=*lower_bound(ps.begin(),ps.end(),p+D);
		long long ans=(long long)p*p*p;
		long long bns=(long long)p*q;
		if(ans>bns)ans=bns;
		printf("%lld\n",ans);
	}
}