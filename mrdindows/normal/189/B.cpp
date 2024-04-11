#include <iostream>
#include <math.h>
#include <algorithm>
typedef unsigned long long lli; 
using namespace std;
const lli mod=1000000007;   
/*
lli step(lli ch,lli st)
{
    if (st==0) return 1;
    if (st==1) return ch%mod;
    else
    {
        lli r=st%2==0? 1: ch;
        return ( step((ch*ch)%mod,st/2)*r)%mod;
    }
}*/
int main()
{
    int x,y;
    lli n=0;
    cin>>x>>y;
        lli t=0;
        int power=2;
    for (int p=0;p<2200;p++)
        {
          if (power>y) break; 
            t+=y+1-power;
                power+=2;
        }
    for (int i=1;i<x;i++)
    {
        y=min(i,x-i);
        n+=y;
    }
    n*=t;
    cout<<n;
    return 0;
}