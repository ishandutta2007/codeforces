#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,A[55];
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%d",&A[i]);
        bool out=false;
        sort(A,A+N);
        for(int i=1;i<N;i++)if(A[i]-A[i-1]>1)out=true;
        puts(out?"NO":"YES");
    }
}