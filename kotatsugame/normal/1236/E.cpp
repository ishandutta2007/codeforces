#include<cstdio>
#include<vector>
using namespace std;
int N,M;
int A[1<<17];
long long ans;
vector<int>X[2<<17];
const int off=1<<17;
main()
{
	scanf("%d%d",&N,&M);
	if(N==1)
	{
		printf("0\n");
		return 0;
	}
	long long R=0;
	for(int i=0;i<M;i++)scanf("%d",A+i);
	vector<int>r(A,A+M);
	for(int i=0;i<2<<17;i++)X[i].clear();
	X[N-1+off].push_back(-1);
	for(int i=0;i<M;i++)
	{
		r[i]-=i+1;
		X[r[i]-1+off].push_back(i);
		int rr=N-i-1;
		X[rr-1+off].push_back(i);
	}
	vector<pair<int,int> >now;
	for(int i=2<<17;i--;)
	{
		int nowc=i>=off&&i<N+off,id=0;
		vector<pair<int,int> >nxt;
		for(int j=0;j<X[i].size();j++)
		{
			while(id<now.size()&&now[id].first<X[i][j])
			{
				nowc+=now[id].second;
				id++;
			}
			R-=nowc;
			nxt.push_back(make_pair(X[i][j],nowc));
			nowc=0;
		}
		now=nxt;
	}
	long long L=0;
	vector<int>l(A,A+M);
	for(int i=0;i<2<<17;i++)X[i].clear();
	X[0].push_back(-1);
	for(int i=0;i<M;i++)
	{
		l[i]+=i+1;
		X[l[i]-1].push_back(i);
		int ll=1+i+1;
		X[ll-1].push_back(i);
	}
	now.clear();
	for(int i=0;i<2<<17;i++)
	{
		int nowc=i<N,id=0;
		vector<pair<int,int> >nxt;
		for(int j=0;j<X[i].size();j++)
		{
			while(id<now.size()&&now[id].first<X[i][j])
			{
				nowc+=now[id].second;
				id++;
			}
			L-=nowc;
			nxt.push_back(make_pair(X[i][j],nowc));
			nowc=0;
		}
		now=nxt;
	}
	printf("%lld\n",(long long)N*(2*M+4)+L+R-N);
}