#include<cstdio>
using namespace std;
int T,N;
int A[150015];
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%d",&A[i]);
        int mn=1e9;
        int cnt=0;
        for(int i=N;i--;)
        {
            if(mn<A[i])cnt++;
            else mn=A[i];
        }
        printf("%d\n",cnt);
    }
}