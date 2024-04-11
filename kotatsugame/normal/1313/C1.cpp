#include<cstdio>
#include<stack>
using namespace std;
int N;
long long M[500000];
long long L[500000],R[500000];
int ans[500000];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%lld",&M[i]);
	stack<pair<long long,long long> >lf,rg;
	lf.push(make_pair(0LL,-1LL));
	for(int i=0;i<N;i++)
	{
		long long diff=0;
		while(lf.top().first>M[i])
		{
			pair<long long,long long>p=lf.top();lf.pop();
			diff-=p.first*(p.second-lf.top().second);
		}
		diff+=M[i]*(i-lf.top().second);
		lf.push(make_pair(M[i],i));
		L[i]=(i==0?0LL:L[i-1])+diff;
	}
	rg.push(make_pair(0LL,(long long)N));
	for(int i=N;i--;)
	{
		long long diff=0;
		while(rg.top().first>M[i])
		{
			pair<long long,long long>p=rg.top();rg.pop();
			diff-=p.first*(rg.top().second-p.second);
		}
		diff+=M[i]*(rg.top().second-i);
		rg.push(make_pair(M[i],i));
		R[i]=(i==N-1?0LL:R[i+1])+diff;
	}
	int mid=0;
	for(int i=1;i<N;i++)
	{
		if(L[mid]+R[mid]-M[mid]<L[i]+R[i]-M[i])
		{
			mid=i;
		}
	}
	ans[mid]=M[mid];
	for(int i=mid-1;i>=0;i--)
	{
		ans[i]=M[i];
		if(ans[i]>ans[i+1])ans[i]=ans[i+1];
	}
	for(int i=mid+1;i<N;i++)
	{
		ans[i]=M[i];
		if(ans[i]>ans[i-1])ans[i]=ans[i-1];
	}
	for(int i=0;i<N;i++)printf("%d%c",ans[i],i==N-1?'\n':' ');
}