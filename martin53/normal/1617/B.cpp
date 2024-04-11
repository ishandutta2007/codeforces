#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    scanf("%i",&n);

    for(int c=1;true;c++)
        for(int b=2*c;true;b+=c)
        {
            int a=n-b-c;

            if(a<=b)break;

            if(__gcd(a,b)==c)
            {
                printf("%i %i %i\n",a,b,c);
                return;
            }
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