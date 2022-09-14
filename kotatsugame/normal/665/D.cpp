#include<cstdio>
#include<vector>
using namespace std;
int N;
bool isp[2<<20];
main()
{
	for(int i=2;i<2<<20;i++)isp[i]=true;
	for(int i=2;i<2<<20;i++)if(isp[i])
	{
		for(int j=i+i;j<2<<20;j+=i)isp[j]=false;
	}
	scanf("%d",&N);
	vector<int>E,O;
	int co=0;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		if(A==1)co++;
		else if(A%2==0)E.push_back(A);
		else O.push_back(A);
	}
	vector<int>ans;
	if(co>0)ans.push_back(1);
	else if(!E.empty())ans.push_back(E[0]);
	else ans.push_back(O[0]);
	if(co>0)
	{
		vector<int>now(co,1);
		for(int e:E)if(isp[e+1])
		{
			now.push_back(e);
			break;
		}
		if(ans.size()<now.size())ans=now;
	}
	for(int e:E)for(int o:O)if(isp[e+o])
	{
		if(ans.size()<2)
		{
			ans.clear();
			ans.push_back(e);
			ans.push_back(o);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
}