#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<K;i++)A[i]=i+1;
		reverse(A+K-(N-K)-1,A+K);
		for(int i=0;i<K;i++)printf("%d%c",A[i],i+1==K?10:32);
	}
}