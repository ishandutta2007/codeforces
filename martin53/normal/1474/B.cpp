#include<bits/stdc++.h>
using namespace std;

bool prime(int val)
{
    for(int i=2;i*i<=val;i++)
        if(val%i==0)return 0;

    return 1;
}
int nxt(int val)
{
    while(prime(val)==0)val++;
    return val;
}
int solve()
{
    int d;
    scanf("%i",&d);

    int p=nxt(1+d);

    int q=nxt(p+d);

    return p*q;
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