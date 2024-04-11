#include<cstdio>
#include<map>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	map<int,int>mp;
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		for(int j=1;j<=30;j++)
		{
			int t=(1<<j)-A;
			if(mp.find(t)!=mp.end())ans+=mp[t];
		}
		mp[A]++;
	}
	printf("%lld\n",ans);
}