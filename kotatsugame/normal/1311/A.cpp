#include<cstdio>
using namespace std;
int T,A,B;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d%d",&A,&B);
        if(A==B)puts("0");
        else if(A<B&&(B-A)%2==1||A>B&&(A-B)%2==0)puts("1");
        else puts("2");
    }
}