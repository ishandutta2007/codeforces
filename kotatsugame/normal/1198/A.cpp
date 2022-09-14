#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N,I,K;
map<int,int>M;
main()
{
	scanf("%d%d",&N,&I);
	for(int i=0;i<N;i++)
	{
		int a;scanf("%d",&a);
		M[a]++;
	}
	I=I*8/N;
	if(I>20)
	{
		puts("0");
		return 0;
	}
	K=1;
	while(K*2<=(1<<I))K*=2;
	if(K>=M.size())
	{
		puts("0");
		return 0;
	}
	vector<pair<int,int> >A;
	for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
	{
		A.push_back(make_pair(it->first,it->second));
	}
	sort(A.begin(),A.end());
	int now=0;
	for(int i=K;i<A.size();i++)now+=A[i].second;
	int ans=now;
	for(int i=0;i+K<A.size();i++)
	{
		now+=A[i].second;
		now-=A[i+K].second;
		ans=min(ans,now);
	}
	printf("%d\n",ans);
}