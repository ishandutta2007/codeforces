#include<bits/stdc++.h>
using namespace std;

int x,y,a,b;

bool can(long long w)
{
    long long s_low=0;
    long long s_high=w;

    if(x-w*b<0)return 0;

    s_high=min(s_high,(x-w*b)/(a-b));

    s_low=max(s_low,(w*a-y+a-b-1)/(a-b));

    return s_low<=s_high;
}

int solve()
{
    scanf("%i%i%i%i",&x,&y,&a,&b);

    if(a==b)return min(x,y)/a;

    if(a<b)
    {
        swap(a,b);
        swap(x,y);
    }

    //a>b
    int ok=0,not_ok=1e9+1;
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;
        if(can(av))ok=av;
        else not_ok=av;
    }

    return ok;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%i\n",solve());
    }

    return 0;
}