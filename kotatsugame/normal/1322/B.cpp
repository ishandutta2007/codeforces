#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[4<<17],B[4<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	long long ans=0;
	for(int i=25;i>=0;i--)
	{
		int bit=1<<i;
		for(int j=0;j<N;j++)
		{
			B[j]=A[j]&(bit*2-1);
		}
		sort(B,B+N);
		long long cnt=0;
		for(int j=0;j<N;j++)
		{
			cnt+=lower_bound(B,B+N,4*bit-B[j])-lower_bound(B,B+N,3*bit-B[j]);
			cnt+=lower_bound(B,B+N,2*bit-B[j])-lower_bound(B,B+N,1*bit-B[j]);
			if((2*B[j])&bit)cnt--;
		}
		if(cnt/2%2==1)ans+=bit;
	}
	printf("%lld\n",ans);
}