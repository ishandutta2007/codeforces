#include<cstdio>
using namespace std;
long long K;
long long cnt[10];
main()
{
	scanf("%lld",&K);
	for(int i=0;;i++)
	{
		long long now=1;
		for(int j=0;j<10;j++)now*=cnt[j];
		if(now>=K)break;
		cnt[i%10]++;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<cnt[i];j++)printf("%c","codeforces"[i]);
	}
	printf("\n");
}