#include<cstdio>
using namespace std;
int T,N;
int A[50],B[50];
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        int mA=1e9,mB=1e9;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
            if(mA>A[i])mA=A[i];
        }
        for(int i=0;i<N;i++)
        {
            scanf("%d",&B[i]);
            if(mB>B[i])mB=B[i];
        }
        long long ans=0;
        for(int i=0;i<N;i++)
        {
            int x=A[i]-mA,y=B[i]-mB;
            ans+=x<y?y:x;
        }
        printf("%lld\n",ans);
    }
}