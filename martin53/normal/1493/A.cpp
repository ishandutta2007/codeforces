#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;

    scanf("%i%i",&n,&k);

    vector<int> outp={};

    for(int i=1;i<k;i++)
        if(i>=k-i)outp.push_back(i);

    for(int i=k+1;i<=n;i++)outp.push_back(i);

    printf("%i\n",outp.size());
    for(auto w:outp)printf("%i ",w);printf("\n");
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