#include<cstdio>
using namespace std;
int T,x,y,n;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d%d%d",&x,&y,&n);
        printf("%d\n",y+(n-y)/x*x);
    }
}