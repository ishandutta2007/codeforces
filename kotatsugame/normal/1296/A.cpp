#include<cstdio>
using namespace std;
int T,N;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        int e=0,o=0;
        for(int i=0;i<N;i++)
        {
            int a;scanf("%d",&a);
            if(a%2)o++;else e++;
        }
        puts(o&&e||o&&N%2?"YES":"NO");
    }
}