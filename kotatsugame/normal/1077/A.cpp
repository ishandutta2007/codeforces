#include<cstdio>
using namespace std;
int T;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        long long A,B,K;
        scanf("%lld%lld%lld",&A,&B,&K);
        if(K%2==0)
        {
            printf("%lld\n",(A-B)*(K/2));
        }
        else
        {
            printf("%lld\n",(A-B)*(K/2)+A);
        }
    }
}