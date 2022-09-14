#include<cstdio>
#include<vector>
using namespace std;
int N,M;
int L[100],R[100];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d%d",&L[i],&R[i]);
	vector<int>ans;
	for(int x=1;x<=M;x++)
	{
		bool cont=false;
		for(int i=0;i<N;i++)if(L[i]<=x&&x<=R[i])cont=true;
		if(!cont)ans.push_back(x);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
}