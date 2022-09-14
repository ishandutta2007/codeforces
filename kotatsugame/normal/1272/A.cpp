#include<cstdio>
#include<algorithm>
using namespace std;
int T,A,B,C;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d%d%d",&A,&B,&C);
        int ans=-1;
        for(int a=A-1;a<=A+1;a++)for(int b=B-1;b<=B+1;b++)for(int c=C-1;c<=C+1;c++)
        {
            int now=abs(a-b)+abs(b-c)+abs(c-a);
            if(ans==-1||ans>now)ans=now;
        }
        printf("%d\n",ans);
    }
}