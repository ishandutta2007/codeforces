#include<bits/stdc++.h>
using namespace std;

const int MX=1e6+42;

bool on[MX];

int main()
{
    int n;

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        on[cur]=1;
    }

    int outp=-n;

    for(int i=1;i<MX;i++)
    {
        int g=0;

        for(int j=i;j<MX;j+=i)
            if(on[j])
                g=__gcd(g,j);

        if(g==i)outp++;
    }

    printf("%i\n",outp);

    return 0;
}