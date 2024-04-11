#include <stdio.h>
#include <algorithm>
using namespace std;

int A[200002];

int main()
{
    int N;
    scanf ("%d",&N);
    for (int i=0;i<N;i++){
        scanf ("%d",&A[i]);
        A[i] -= N-1-i;
    }
    sort(A,A+N);
    for (int i=0;i<N;i++) A[i] += N-1-i;
    for (int i=1;i<N;i++) if (A[i-1] > A[i]){
        puts(":(");
        return 0;
    }
    for (int i=0;i<N;i++) printf ("%d ",A[i]);
    return 0;
}