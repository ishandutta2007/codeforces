#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,i[8],k,f=1,u,y,o[40500],l,sum,ma=-1,mi;
    cin>>n>>m;
    for(k=0;k<n;k++)
    i[k]=k+1;
    for(k=2;k<=n;k++)
    f*=k;
    for(k=0;k<f;k++)
    {
        sum=0;
        for(u=0;u<n;u++)
        for(y=u;y<n;y++)
        {
            mi=1e9;
            for(l=u;l<=y;l++)
            mi=min(mi,i[l]);
            sum+=mi;
        }
        o[k]=sum;
        ma=max(ma,sum);
        next_permutation(i,i+n);
    }
    u=0;
    for(k=0;u!=m;k++)
    if(o[k]==ma) u++;
    for(y=1;y<k;y++)
    next_permutation(i,i+n);
    for(k=0;k<n;k++)
    cout<<i[k]<<' ';
    return 0;
}