#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
long long n,m,k;
long long inp[nmax];

long long get_page(long long id,long long removed)
{
    long long where=id-removed;
    return (where+k-1)/k;
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%lld",&inp[i]);

    sort(inp+1,inp+m+1);

    int output=0;
    for(int i=1;i<=m;i++)
    {
        int j=i;
        while(j<=m&&get_page(inp[i],i-1)==get_page(inp[j],i-1))j++;
        output++;
        i=j-1;
    }

    printf("%i\n",output);
    return 0;
}