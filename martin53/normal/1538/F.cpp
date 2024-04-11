#include<bits/stdc++.h>
using namespace std;

int pref(int r)
{
    int ret=0;

    while(r)
    {
        ret=ret+r;
        r=r/10;
    }

    return ret;
}
int solve()
{
    int l,r;

    scanf("%i%i",&l,&r);

    return pref(r)-pref(l);
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