#include <bits/stdc++.h>
using namespace std;
int v[103];
int get (int n)
{
    int i=0;
    for(i=1;i<n;++i)
    {
        if(v[i]<v[i+1])
        {
            ++v[i];
            return i;
        }
    }
    return -1;
}
int main()
{
    long long t,n,i,j,m,k=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int rzc;
        for(i=1;i<=k;++i)
        {
            rzc=get(n);
            if(rzc==-1)
                break;
        }
        cout<<rzc<<'\n';
    }
    return 0;
}