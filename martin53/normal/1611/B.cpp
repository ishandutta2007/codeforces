#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int a,b;

    scanf("%i%i",&a,&b);

    if(a>b)swap(a,b);

    int outp=min(a,(b-a)/2);

    a=a-outp;
    b=b-3*outp;

    return outp+a/2;
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