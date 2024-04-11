#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int a,b;

    scanf("%i%i",&a,&b);

    int outp=b-a;

    for(int x=0;x<outp;x++)outp=min(outp,x+1+((a+x)|b)-b);

    for(int y=0;y<outp;y++)outp=min(outp,y+1+(a|(b+y))-(b+y));

    return outp;
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