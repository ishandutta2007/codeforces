#include<cstdio>
using namespace std;
int T,N;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        int c2=0,c3=0;
        while(N%2==0)N/=2,c2++;
        while(N%3==0)N/=3,c3++;
        if(N>1||c2>c3)puts("-1");
        else
        {
            printf("%d\n",c3-c2+c3);
        }
    }
}