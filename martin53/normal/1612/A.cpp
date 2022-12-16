#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y;
    scanf("%i%i",&x,&y);

    if((x+y)%2)printf("-1 -1\n");
    else
    {
        int m=(x+y)/2;

        if(m<=x)printf("%i %i\n",m,0);
        else printf("%i %i\n",0,m);
    }
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