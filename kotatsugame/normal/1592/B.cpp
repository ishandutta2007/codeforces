#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,X;
int A[1<<17];
main()
{
	scanf("%d",&T);
	vector<int>B;
	for(;T--;)
	{
		scanf("%d%d",&N,&X);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		if(N-X>=1+X)puts("YES");
		else
		{
			B.clear();
			for(int i=0;i<N-X;i++)B.push_back(A[i]);
			for(int i=X;i<N;i++)B.push_back(A[i]);
			sort(B.begin(),B.end());
			for(int i=0;i<N-X;i++)A[i]=B[i];
			for(int i=X;i<N;i++)A[i]=B[N-X+(i-X)];
			bool ok=true;
			for(int i=1;i<N;i++)if(A[i]<A[i-1])ok=false;
			puts(ok?"YES":"NO");
		}
	}
}