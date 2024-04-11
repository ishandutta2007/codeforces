#include <bits/stdc++.h>
using namespace std;

long long v[100005];
int main()
{
    long long i,j,m,n,k=0,q,n1,n2;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    int l=0,r=n+1,cnt=0;
    while(l<r-1)
    {
        long long s=v[--r];
        long long val=v[r];
        while(l+1<r && s<=m)
        {
            ++l;
            s+=val;
        }
        if(s>m)
            ++cnt;
        else
            break;
    }
    cout<<cnt;
    return 0;
}