#include<cstdio>
#include<vector>
using namespace std;
int T,N;
int A[1<<17];
int cnt[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;i++)cnt[i]=0;
		int mi=1;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			cnt[A[i]]++;
			if(cnt[mi]<cnt[A[i]])mi=A[i];
		}
		if(cnt[mi]>(N+1)/2)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=N;i++)cnt[i]=0;
		mi=1;
		int p=0,a2=0;
		vector<pair<int,int> >X;
		for(int i=0;i<N;i++)
		{
			if(i==N-1||A[i]==A[i+1])
			{
				if(A[p]==A[i])
				{
					a2++;
					cnt[A[i]]++;
					if(cnt[mi]<cnt[A[i]])mi=A[i];
				}
				else X.push_back(make_pair(A[p],A[i]));
				p=i+1;
			}
		}
		int mx=cnt[mi];
		int diff=a2-mx+1;
		for(pair<int,int>p:X)if(p.first!=mi&&p.second!=mi)diff++;
		int t=mx-diff;
		if(t<0)t=0;
		printf("%d\n",(int)X.size()+a2-1+t);
	}
}