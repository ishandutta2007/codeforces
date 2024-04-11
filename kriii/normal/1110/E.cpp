#include <stdio.h>
#include <algorithm>
using namespace std;

int N,A[100100],B[100100];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%d",&A[i]);
	for (int i=0;i<N;i++) scanf ("%d",&B[i]);
	for (int i=N-1;i>=1;i--){
		A[i] -= A[i-1];
		B[i] -= B[i-1];
	}
	sort(A+1,A+N);
	sort(B+1,B+N);
	for (int i=0;i<N;i++) if (A[i] != B[i]){
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}