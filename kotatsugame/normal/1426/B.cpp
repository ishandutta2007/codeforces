#include<cstdio>
using namespace std;
int T,N,M;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d%d",&N,&M);
        bool fn=false;
        for(int i=0;i<N;i++)
        {
            int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
            if(b==c)fn=true;
        }
        puts(fn&&M%2==0?"YES":"NO");
    }
}