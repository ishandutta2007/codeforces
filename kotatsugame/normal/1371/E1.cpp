#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,P;
int A[2020];
main()
{
	scanf("%d%d",&N,&P);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	int L=A[N-1]-(N-1);
	if(L<1)L=1;
	int R=A[N-1]-1;
	vector<int>ans;
	for(int x=L;x<=R;x++)
	{
		bool ok=true;
		int id=0;
		for(int i=0;i<N;i++)
		{
			while(id<N&&A[id]<=x+i)id++;
			if(id<i||(id-i)%P==0)
			{
				ok=false;
				break;
			}
		}
		if(ok)ans.push_back(x);
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d",ans[i]);
		if(i+1<ans.size())printf(" ");
	}
	printf("\n");
}