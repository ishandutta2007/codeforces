#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    set<int> in={};

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int d=inp[i]-inp[j];

            if(d>0)in.insert(d);
        }

    printf("%i\n",in.size());
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