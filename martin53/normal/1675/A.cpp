#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int a,b,c,x,y;

    scanf("%i%i%i%i%i",&a,&b,&c,&x,&y);

    x=max(x-a,0);
    y=max(y-b,0);

    return x+y<=c;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}