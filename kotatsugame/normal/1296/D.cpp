#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,A,B,K;
main()
{
	scanf("%d%d%d%d",&N,&A,&B,&K);
	vector<int>H(N);
	for(int i=0;i<N;i++)
	{
		int h;scanf("%d",&h);h--;h%=A+B;
		H[i]=h/A;
	}
	sort(H.begin(),H.end());
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(H[i]<=K)
		{
			K-=H[i];
			ans++;
		}
	}
	printf("%d\n",ans);
}