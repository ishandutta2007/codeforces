#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n,l,r,k;
    scanf("%i%i%i%i",&n,&l,&r,&k);

    vector<int> inp={};

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        if(l<=cur&&cur<=r)inp.push_back(cur);
    }

    sort(inp.begin(),inp.end());

    int outp=0;
    for(auto w:inp)
    {
        if(k>=w)
        {
            outp++;
            k=k-w;
        }
        else break;
    }

    return outp;
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