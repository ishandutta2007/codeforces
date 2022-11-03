#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c,d,e,f,g;
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    e=2*a;
    f=2*b;
    g=max(c,d);
    if(c*2>=g && d<=e && d<=f && d*2>=g && d*2<e && d*2<f)
        printf("%d\n%d\n%d\n",e,f,g);
    else
        printf("-1");
    return 0;
}