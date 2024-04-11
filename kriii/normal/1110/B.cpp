#include <stdio.h>
#include <algorithm>
using namespace std;

int N,M,K,B[100100];

int main()
{
	scanf ("%d %d %d",&N,&M,&K);
	for (int i=0;i<N;i++) scanf ("%d",&B[i]);

	int ans = B[N-1] - B[0] + 1;
	for (int i=N-1;i>=1;i--) B[i] -= B[i-1];
	sort(B+1,B+N);
	reverse(B+1,B+N);
	for (int i=1;i<K;i++){
		ans -= B[i]-1;
	}
	printf ("%d\n",ans);

	return 0;
}