#include<cstdio>
using namespace std;
int N,R;
int A[1010];
main()
{
	scanf("%d%d",&N,&R);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int prv=-1;
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(prv<i)
		{
			int j=i+R-1;
			if(j>=N)j=N-1;
			while(j>=0&&j>=i-R+1&&A[j]==0)j--;
			if(j<0||j<i-R+1)
			{
				puts("-1");
				return 0;
			}
			prv=j+R-1;
			ans++;
		}
	}
	printf("%d\n",ans);
}