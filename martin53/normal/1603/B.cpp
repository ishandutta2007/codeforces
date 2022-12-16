#include<bits/stdc++.h>
using namespace std;

long long solve()//n mod x = y mod n
{
    int x,y;
    scanf("%i%i",&x,&y);

    if(x>y)return y+x;
    if(y%x==0)return x;

    //x<y
    int q=(y/2)%(x/2);
    return y-q;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%lld\n",solve());
    }

    return 0;
}