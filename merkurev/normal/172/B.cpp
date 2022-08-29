#include <cstdio>
#include <iostream>

using namespace std;

int fir[100500];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a,b,m,r,num=1;
    scanf("%d%d%d%d",&a,&b,&m,&r);

    while (fir[r]==0)
    {
        fir[r]=num++;
        long long rr=long long(a*r+b)%long long(m);
        r=rr;
    }

    printf("%d",num-fir[r]);

    return 0;
}