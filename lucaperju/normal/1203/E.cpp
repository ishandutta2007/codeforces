#include <bits/stdc++.h>
using namespace std;
int v[150003];
int ok[150003];
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,i,j,s=0,k,l,t;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
    {
        if(ok[v[i]-1]==0 && v[i]!=1)
        {
            ok[v[i]-1]=1;
            ++s;
        }
        else
        if(ok[v[i]]==0)
        {
            ok[v[i]]=1;
            ++s;
        }
        else
        if(ok[v[i]+1]==0)
        {
            ok[v[i]+1]=1;
            ++s;
        }
    }
    cout<<s;
    return 0;
}