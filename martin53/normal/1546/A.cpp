#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,a[nmax],b[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=n;i++)scanf("%i",&b[i]);

    vector< pair<int,int> > outp={};

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            while(a[i]>b[i]&&a[j]<b[j])
            {
                outp.push_back({i,j});
                a[i]--;
                a[j]++;
            }

    for(int i=1;i<=n;i++)
        if(a[i]!=b[i])
        {
            printf("-1\n");
            return;
        }

    printf("%i\n",outp.size());
    for(auto w:outp)printf("%i %i\n",w.first,w.second);
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