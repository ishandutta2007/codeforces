#include<bits/stdc++.h>
using namespace std;
long long i,j,k,l,n,m,a,b,t;

int checkmax(long long nn, long long aa, long long bb)
{
    long long jj=aa+bb;
    if(jj-nn+1<=0)
    {
        return 1;
    } else if(jj-nn+1>nn)
    {
        return nn;
    }
    {
        return jj-nn+1;
    }
}

int checkmin(long long nn, long long aa, long long bb)
{
    long long jj=aa+bb;
    if(jj-1>n)
    {
        return n;
    } else
    {
        return jj-1;
    }
}

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>a>>b;
        cout<<checkmax(n,a,b)<<" "<<checkmin(n,a,b)<<"\n";
    }
    return 0;
}