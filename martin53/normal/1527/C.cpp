#include<bits/stdc++.h>
using namespace std;

long long eval(vector<int> v,int n)
{
    long long ret=0,sum=0;

    for(auto w:v)
    {
        ret+=sum*(n-w+1);

        sum+=w;
    }

    return ret;
}
long long solve()
{
    int n;

    scanf("%i",&n);

    map<int, vector<int> > seen={};

    for(int i=1;i<=n;i++)
    {
        int val;

        scanf("%i",&val);

        seen[val].push_back(i);
    }

    long long outp=0;

    for(auto w:seen)
        outp+=eval(w.second,n);

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