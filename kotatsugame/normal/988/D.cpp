#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int N;
int X[2<<17];
vector<int>ans;
bool fn[32];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&X[i]);
	}
	set<int>S(X,X+N);
	ans.push_back(X[0]);
	for(int i=0;ans.size()<3&&i<N;i++)
	{
		for(int j=0;j<=30;j++)
		{
			fn[j]=S.find(X[i]+(1<<j))!=S.end();
		}
		for(int j=0;j<=30;j++)if(fn[j])
		{
			if(fn[j+1])
			{
				ans.clear();
				ans.push_back(X[i]);
				ans.push_back(X[i]+(1<<j));
				ans.push_back(X[i]+(1<<j+1));
				break;
			}
			if(ans.size()==1)
			{
				ans.clear();
				ans.push_back(X[i]);
				ans.push_back(X[i]+(1<<j));
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
}