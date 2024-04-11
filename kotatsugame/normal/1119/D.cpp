#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,Q;
long long s[1<<17],diff[1<<17],ds[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%lld",s+i);
	sort(s,s+N);
	for(int i=1;i<N;i++)diff[i-1]=s[i]-s[i-1];
	sort(diff,diff+N-1);
	for(int i=1;i<N;i++)ds[i]=ds[i-1]+diff[i-1];
	scanf("%d",&Q);
	for(;Q--;)
	{
		long long L,R;
		scanf("%lld%lld",&L,&R);
		int id=upper_bound(diff,diff+N-1,R-L+1)-diff;
		printf("%lld%c",s[N-1]-s[0]+R-L+1-((ds[N-1]-ds[id])-(R-L+1)*(N-1-id)),Q==0?'\n':' ');
	}
}