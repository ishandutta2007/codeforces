#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n;

long long k,x;

long long inp[nmax];

int main()
{
    scanf("%i%lld%lld",&n,&k,&x);

    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    sort(inp+1,inp+n+1);

    int outp=1;

    vector<long long> need={};

    for(int i=1;i<n;i++)
        if(inp[i+1]-inp[i]>x)
        {
            outp++;
            need.push_back((inp[i+1]-inp[i]-1)/x);
        }

    sort(need.begin(),need.end());

    for(auto w:need)
    {
        if(w<=k)
        {
            k=k-w;
            outp--;
        }
    }

    printf("%i\n",outp);

    return 0;
}