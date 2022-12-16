#include<bits/stdc++.h>
using namespace std;

const int MX=1e6+42;

int solve()
{
    int x1,p1,x2,p2;

    scanf("%i%i%i%i",&x1,&p1,&x2,&p2);

    int m=min(p1,p2);

    p1=p1-m;
    p2=p2-m;

    while(p1&&x1<MX)
    {
        p1--;
        x1=x1*10;
    }

    while(p2&&x2<MX)
    {
        p2--;
        x2=x2*10;
    }

    if(x1<x2)return '<';
    if(x1==x2)return '=';
    return '>';
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%c\n",solve());
    }

    return 0;
}