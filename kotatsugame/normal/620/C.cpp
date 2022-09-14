#include<cstdio>
#include<set>
#include<vector>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	set<int>S;
	vector<pair<int,int> >X;
	int l=0;
	for(int r=0;r<N;r++)
	{
		int a;scanf("%d",&a);
		if(S.find(a)!=S.end())
		{
			S.clear();
			X.push_back(make_pair(l,r));
			l=r+1;
		}
		else S.insert(a);
	}
	if(l==0)puts("-1");
	else
	{
		if(l<N)X.back().second=N-1;
		printf("%d\n",X.size());
		for(pair<int,int>p:X)printf("%d %d\n",p.first+1,p.second+1);
	}
}