#include<cstdio>
#include<algorithm>
using namespace std;
int N,X[3<<17];
main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&X[i]);
    sort(X,X+N);
    printf("%d\n",X[(N-1)/2]);
}