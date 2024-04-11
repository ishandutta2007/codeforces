#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int cnt[101];
main()
{
	scanf("%d",&N);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
		ans+=a;
	}
	int mn=0;
	for(int i=1;i<100;i++)if(cnt[i])for(int j=i+1;j<=100;j++)if(cnt[j])
	{
		for(int k=1;k<=j;k++)if(j%k==0)mn=min(mn,j/k+i*k-i-j);
	}
	printf("%d\n",ans+mn);
}