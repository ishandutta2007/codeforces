#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int MX=0;
    vector<int> ids={};

    for(int i=1;i<=n;i++)
        if(MX<inp[i])
        {
            MX=inp[i];
            ids.push_back(i);
        }

    ids.push_back(n+1);

    for(int i=ids.size()-2;i>=0;i--)
    {
        for(int j=ids[i];j<ids[i+1];j++)printf("%i ",inp[j]);
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