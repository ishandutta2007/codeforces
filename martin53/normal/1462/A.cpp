#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int l=1,r=n;

    while(l<=r)
    {
        if((l+r)%2!=n%2)
        {
            printf("%i ",inp[l]);
            l++;
        }
        else
        {
            printf("%i ",inp[r]);
            r--;
        }
    }

    printf("\n");
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