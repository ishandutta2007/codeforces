#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,K;
int A[2<<17],L[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		int t=A[i];
		while(t)t/=10,L[i]++;
	}
	long long ans=0;
	vector<int>mp[10];
	for(int i=0;i<N;i++)
	{
		int t=A[i]%K;
		for(int j=1;j<=10;j++)
		{
			t=(long long)t*10%K;
			mp[j-1].push_back(t);
			if(j==L[i])
			{
				if((t+A[i])%K==0)ans--;
			}
		}
	}
	for(int j=0;j<10;j++)sort(mp[j].begin(),mp[j].end());
	for(int i=0;i<N;i++)
	{
		int t=(K-A[i]%K)%K;
		ans+=upper_bound(mp[L[i]-1].begin(),mp[L[i]-1].end(),t)
			-lower_bound(mp[L[i]-1].begin(),mp[L[i]-1].end(),t);
	}
	printf("%lld\n",ans);
}