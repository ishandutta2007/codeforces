#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

int solve()
{
    int n;

    scanf("%i",&n);

    map<int,int> seen={};

    int mx=0;

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        mx=max(mx,cur);
        seen[cur]++;
    }

    long long outp=1;

    pair<int,int> mult={1,1};

    if(seen[mx]>=2);//n!
    else if(seen[mx-1]==0)mult={0,1};//*0
    else mult={seen[mx-1],seen[mx-1]+1};//n!*(seen[mx-1])/(seen[mx-1]+1)

    outp=mult.first;
    for(int i=1;i<=n;i++)
        if(i!=mult.second)outp=outp*i%mod;

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