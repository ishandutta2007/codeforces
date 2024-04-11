#include<bits/stdc++.h>
using namespace std;

const int nmax=1000;

bitset<nmax> can;

int n,d;

bool check(int num)
{
    while(num)
    {
        if(num%10==d)return 1;
        num=num/10;
    }

    return 0;
}

void solve()
{
    scanf("%i%i",&n,&d);

    can=can^can;
    can[0]=1;

    for(int i=1;i<nmax;i++)
        if(check(i))
        {
            for(int j=i;j<nmax;j++)
                if(can[j-i])can[j]=1;
        }

    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%i",&num);

        if(num>=nmax||can[num])printf("YES\n");
        else printf("NO\n");
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