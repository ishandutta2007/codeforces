#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,P;
int A[1<<17];
int out[3<<17],cnt[3<<17];
main()
{
	scanf("%d%d",&N,&P);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	int L=1;
	for(int i=0;i<N;i++)if(L<A[i]-i)L=A[i]-i;
	int R=A[N-1];
	vector<pair<int,int> >add;
	for(int j=P;j<=N;j++)
	{
		if(j==N)
		{
			add.push_back(make_pair(A[N-1]-N+P,1));
		}
		else
		{
			int a=A[j-1],b=A[j];
			int jd=j;
			add.push_back(make_pair(a-jd+P,1));
			add.push_back(make_pair(a-jd%P+P,-1));
			add.push_back(make_pair(b-jd+P,-1));
			add.push_back(make_pair(b-jd%P+P,1));
		}
	}
	for(pair<int,int>p:add)
	{
		int id=p.first;
		if(id<L-P)
		{
			int k=(L-P-id+P-1)/P;
			id+=P*k;
			cnt[id-(L-P)]+=k*p.second;
		}
		else if(R+P<=id)
		{
			int k=(id-R-P)/P+1;
			id-=P*k;
		}
		out[id-(L-P)]+=p.second;
	}
	for(int i=0;i<3<<17;i++)
	{
		if(i+P<3<<17)out[i+P]+=out[i];
		cnt[i]+=out[i];
	}
	for(int i=1;i<3<<17;i++)cnt[i]+=cnt[i-1];
	vector<int>ans;
	for(int x=L;x<R;x++)
	{
		int id=x-(L-P);
		if(cnt[id]==0)ans.push_back(x);
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d",ans[i]);
		if(i+1<ans.size())printf(" ");
	}
	printf("\n");
}