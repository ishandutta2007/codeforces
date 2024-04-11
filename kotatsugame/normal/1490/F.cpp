#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		map<int,int>mp;
		for(int i=0;i<N;i++)
		{
			int A;
			scanf("%d",&A);
			mp[A]++;
		}
		vector<int>c;
		for(pair<int,int>p:mp)c.push_back(p.second);
		sort(c.begin(),c.end());
		reverse(c.begin(),c.end());
		int ans=N;
		for(int i=0;i<c.size();i++)
		{
			ans=min(ans,N-(i+1)*c[i]);
		}
		printf("%d\n",ans);
	}
}