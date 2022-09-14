#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;i++)scanf("%d",&A[i]);
		int L=1,R=N;
		while(L<=N&&A[L]==L)L++;
		while(R>0&&A[R]==R)R--;
		if(L==N+1)puts("0");
		else
		{
			bool ok=true;
			for(int i=L;i<=R;i++)if(A[i]==i)ok=false;
			puts(ok?"1":"2");
		}
	}
}