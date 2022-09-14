#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,A[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		vector<int>B,C;
		for(int i=0;i<N;i++)
		{
			if(i&&A[i-1]==A[i])C.push_back(A[i]);
			else B.push_back(A[i]);
		}
		for(int c:C)B.push_back(c);
		for(int i=0;i<N;i++)printf("%d%c",B[i],i+1==N?10:32);
	}
}