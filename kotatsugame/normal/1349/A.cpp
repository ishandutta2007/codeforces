#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,A;
bool isp[2<<17];
int inv[2<<17];
vector<int>ps;
vector<int>K[23023];
main()
{
	for(int i=2;i<2<<17;i++)isp[i]=true;
	for(int i=2;i<2<<17;i++)if(isp[i])
	{
		inv[i]=ps.size();
		ps.push_back(i);
		for(int j=i+i;j<2<<17;j+=i)isp[j]=false;
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A);
		for(int j=0;j<ps.size()&&ps[j]*ps[j]<=A;j++)
		{
			int cnt=0;
			while(A%ps[j]==0)
			{
				A/=ps[j];
				cnt++;
			}
			K[j].push_back(cnt);
		}
		if(A>1)
		{
			K[inv[A]].push_back(1);
		}
	}
	long long ans=1;
	for(int i=0;i<ps.size();i++)
	{
		int tm=0;
		while(tm<2&&K[i].size()<N)
		{
			K[i].push_back(0);
			tm++;
		}
		sort(K[i].begin(),K[i].end());
		int x=K[i][1];
		for(int j=0;j<x;j++)ans=ans*ps[i];
	}
	printf("%lld\n",ans);
}