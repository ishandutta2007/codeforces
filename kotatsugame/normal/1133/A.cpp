#include<cstdio>
using namespace std;
int h1,m1,h2,m2;
main()
{
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    int t=h2*60+m2+h1*60+m1;
    t/=2;
    printf("%02d:%02d\n",t/60,t%60);
}