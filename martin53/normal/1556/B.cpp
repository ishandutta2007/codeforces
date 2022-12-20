#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

long long cnt(vector<int> a,vector<int> b)
{
    if(a.size()!=b.size())return -1;

    long long sum=0;

    for(int i=0;i<a.size();i++)
        sum+=abs(a[i]-b[i]);

    return sum;
}
long long solve()
{
    scanf("%i",&n);

    vector<int> given={};

    vector<int> seen[2]={{},{}};

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        if(inp[i]%2==0)given.push_back(i);

        seen[i%2].push_back(i);
    }

    long long outp=-1;

    long long arr[2]={cnt(given,seen[0]),cnt(given,seen[1])};

    for(int i=0;i<2;i++)
        if(outp==-1)outp=arr[i];
        else if(arr[i]>=0)outp=min(outp,arr[i]);

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%lld\n",solve());
    }

    return 0;
}