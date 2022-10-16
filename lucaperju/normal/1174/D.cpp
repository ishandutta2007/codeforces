#include <bits/stdc++.h>

using namespace std;
int v[300005],oc[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j=0,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b;
    cin>>n>>k;
    if(k>=(1<<n))
    {
        cout<<(1<<n)-1<<'\n';
        for(i=1;i<(1<<n);++i)
            cout<<(i xor (i-1))<<' ';
    }
    else
    {
        for(i=1;i<(1<<n);++i)
        {
            if(!oc[i] && i!=k)
            {
                oc[i xor k]=1;
                v[++j]=i;
            }
        }
        cout<<j<<'\n';
        for(i=1;i<=j;++i)
            cout<<(v[i] xor v[i-1])<<' ';
    }
    return 0;
}