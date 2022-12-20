#include<bits/stdc++.h>
using namespace std;

int n;

vector< pair<int,int> > outp;

int main()
{
    scanf("%i",&n);

    for(int i=0;i<=n;i++)
    {
        outp.push_back({i,i});
        outp.push_back({i+1,i});
        outp.push_back({i,i+1});
    }

    outp.push_back({n+1,n+1});

    printf("%i\n",outp.size());

    for(auto k:outp)
    {
        printf("%i %i\n",k.first,k.second);
    }

    return 0;
}