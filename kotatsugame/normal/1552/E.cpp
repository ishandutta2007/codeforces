#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,K;
int A[10101];
bool used[101];
int now[101];
int a[101],b[101];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N*K;i++)scanf("%d",&A[i]);
	for(int l=0;l<N*K;)
	{
		int r=l;
		for(int i=1;i<=N;i++)now[i]=-1;
		int cnt=0;
		while(r<N*K&&cnt<(N+K-2)/(K-1))
		{
			if(now[A[r]]==-1)now[A[r]]=r;
			else if(!used[A[r]])
			{
				used[A[r]]=true;
				a[A[r]]=now[A[r]]+1;
				b[A[r]]=r+1;
				cnt++;
			}
			r++;
		}
		l=r;
	}
	for(int i=1;i<=N;i++)printf("%d %d\n",a[i],b[i]);
}