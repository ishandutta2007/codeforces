#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	vector<pair<int,long long> >A(N);
	for(int i=0;i<N;i++)
	{
		long long x;
		scanf("%lld",&x);
		long long t=x;
		int cnt=0;
		while(t%3==0)t/=3,cnt++;
		A[i]=make_pair(-cnt,x);
	}
	sort(A.begin(),A.end());
	for(int i=0;i<N;i++)printf("%lld%c",A[i].second,i+1==N?10:32);
}