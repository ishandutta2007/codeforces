#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int p[5<<17];
main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)p[i]=1;
	vector<pair<int,int> >A(N);
	A[0]=make_pair(1,1);
	for(int i=2;i<=N;i++)
	{
		if(p[i]==1)
		{
			for(int j=i;j<=N;j+=i)if(p[j]==1)p[j]=i;
		}
		A[i-1]=make_pair(i/p[i],i);
	}
	sort(A.begin(),A.end());
	for(int i=1;i<N;i++)printf("%d%c",A[i].first,i+1==N?'\n':' ');
}