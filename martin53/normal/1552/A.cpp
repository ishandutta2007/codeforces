#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;
char inp[nmax],help[nmax];

int solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
        help[i]=inp[i];
    }

    sort(help+1,help+n+1);

    int ret=0;
    for(int i=1;i<=n;i++)
        if(help[i]!=inp[i])ret++;

    return ret;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<endl;
    }

    return 0;
}