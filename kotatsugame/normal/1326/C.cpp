#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
int P[2<<17];
const long long mod=998244353;
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&P[i]);
	vector<pair<int,int> >A(N);
	for(int i=0;i<N;i++)
	{
		A[i].first=P[i];
		A[i].second=i;
	}
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	long long aL=0;
	vector<int>id;
	for(int i=0;i<K;i++)
	{
		aL+=A[i].first;
		id.push_back(A[i].second);
	}
	sort(id.begin(),id.end());
	long long aR=1;
	for(int i=1;i<K;i++)
	{
		aR=aR*(id[i]-id[i-1])%mod;
	}
	printf("%lld %lld\n",aL,aR);
}