#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N,K;
struct P{
	long long A,C;
	bool operator<(const P&rhs)const
	{
		long long l=C*(A/C)*(A/C)+A%C*(2*(A/C)+1)-(C+1)*(A/(C+1))*(A/(C+1))-A%(C+1)*(2*(A/(C+1))+1);
		long long r=rhs.C*(rhs.A/rhs.C)*(rhs.A/rhs.C)+rhs.A%rhs.C*(2*(rhs.A/rhs.C)+1)-(rhs.C+1)*(rhs.A/(rhs.C+1))*(rhs.A/(rhs.C+1))-rhs.A%(rhs.C+1)*(2*(rhs.A/(rhs.C+1))+1);
		return l<r;
	}
};
main()
{
	scanf("%d%d",&N,&K);
	priority_queue<P>Q;
	for(int i=0;i<N;i++)
	{
		long long A;
		scanf("%lld",&A);
		P now;
		now.A=A;
		now.C=1;
		Q.push(now);
	}
	for(int i=0;i<K-N;i++)
	{
		P now=Q.top();Q.pop();
		now.C++;
		Q.push(now);
	}
	long long ans=0;
	while(!Q.empty())
	{
		P now=Q.top();Q.pop();
		long long A=now.A;
		long long T=now.C;
		long long L=A/T;
		ans+=(T-A%T)*L*L+A%T*(L+1)*(L+1);
	}
	printf("%lld\n",ans);
}