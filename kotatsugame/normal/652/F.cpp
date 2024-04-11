#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
long long T;
int X[3<<17];
int ans[3<<17];
main()
{
	scanf("%d%d%lld",&N,&M,&T);
	vector<pair<pair<int,int>,int> >A(N);
	for(int i=0;i<N;i++)
	{
		char c;
		int s,r;
		scanf("%d %c",&s,&c);
		s%=M;
		r=c=='L'?0:1;
		A[i]=make_pair(make_pair(s,r),i);
	}
	sort(A.begin(),A.end());
	for(int i=0;i<N;i++)
	{
		int s=A[i].first.first,r=A[i].first.second;
		if(r==0)X[i]=(s-T%M+M)%M;
		else X[i]=(s+T)%M;
	}
	int one=X[0];
	sort(X,X+N);
	int cnt=0;
	int st=lower_bound(X,X+N,one)-X;
	if(A[0].first.second==0)
	{
		for(int i=0;i<N;i++)if(A[i].first.second==1)
		{
			int d=(A[0].first.first-A[i].first.first+M)%M;
			if(2*T>=d)
			{
				long long t=2*T-d;
				t/=M;
				cnt=(cnt+t+1)%N;
			}
		}
		cnt=(N-cnt)%N;
	}
	else
	{
		for(int i=0;i<N;i++)if(A[i].first.second==0)
		{
			int d=(A[i].first.first-A[0].first.first+M)%M;
			if(2*T>d)
			{
				long long t=2*T-d-1;
				t/=M;
				cnt=(cnt+t+1)%N;
			}
		}
	}
	st=(st-cnt+N)%N;
	for(int i=0;i<N;i++)
	{
		int x=X[(st+i)%N];
		if(x==0)x=M;
		ans[A[i].second]=x;
	}
	for(int i=0;i<N;i++)
	{
		printf("%d%c",ans[i],i+1==N?10:32);
	}
}