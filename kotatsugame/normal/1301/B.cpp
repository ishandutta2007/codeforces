#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N;scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
		}
		vector<int>X;
		int M=0;
		for(int i=1;i<N;i++)
		{
			if(A[i-1]==-1)
			{
				if(A[i]!=-1)
				{
					X.push_back(A[i]);
				}
			}
			else
			{
				if(A[i]==-1)
				{
					X.push_back(A[i-1]);
				}
				else
				{
					M=max(M,abs(A[i]-A[i-1]));
				}
			}
		}
		int k;
		if(X.empty())
		{
			k=0;
		}
		else
		{
			sort(X.begin(),X.end());
			k=(X[0]+X.back())/2;
			M=max(M,max(abs(X[0]-k),abs(X.back()-k)));
		}
		printf("%d %d\n",M,k);
	}
}