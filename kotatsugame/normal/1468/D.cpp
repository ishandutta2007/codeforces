#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,M,A,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d",&N,&M,&A,&B);
		vector<int>s(M);
		for(int i=0;i<M;i++)scanf("%d",&s[i]);
		sort(s.begin(),s.end());
		if(A>B)
		{
			A=N+1-A;
			B=N+1-B;
		}
		int cnt=0;
		int t=B-A-2;
		for(int i=0;i<M;i++)s[i]=B-2-s[i];
		int pre=-1;
		for(int i=M;i--;)
		{
			if(pre>=t)break;
			if(s[i]<=pre)continue;
			cnt++;
			pre++;
		}
		printf("%d\n",cnt);
	}
}