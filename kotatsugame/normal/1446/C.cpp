#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int up(int a){return a==0?0:32-__builtin_clz(a);}
pair<int,int>calc(vector<int>A)
{
	if(A.size()<=1)return make_pair((int)A.size(),0);
	vector<vector<int> >nA(33);
	for(int a:A)
	{
		int k=up(a);
		if(k>0)a^=1<<k-1;
		nA[k].push_back(a);
	}
	vector<int>X;
	int sum=0;
	for(int i=0;i<33;i++)if(!nA[i].empty())
	{
		pair<int,int>p=calc(nA[i]);
		sum+=p.first-1;
		X.push_back(p.second-p.first+1);
	}
	int ans=sum;
	for(int i=0;i<X.size();i++)
	{
		ans=min(ans,sum+min(X[i],i+1<X.size()?X[i+1]:0));
		sum++;
	}
	return make_pair((int)A.size(),ans);
}
main()
{
	int N;
	scanf("%d",&N);
	vector<int>A(N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	printf("%d\n",calc(A).second);
}