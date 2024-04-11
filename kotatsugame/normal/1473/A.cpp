#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,D;
int A[100];
main(){
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&D);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		puts(A[0]+A[1]<=D||A[N-1]<=D?"YES":"NO");
	}
}