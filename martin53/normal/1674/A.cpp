#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y;
    scanf("%i%i",&x,&y);

    if(y%x==0)printf("1 %i\n",y/x);
    else printf("0 0\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}