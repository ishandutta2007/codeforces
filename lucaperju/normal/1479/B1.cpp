#include <bits/stdc++.h>
using namespace std;
int v[100003];
int a[100003],b[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,m,k=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    int cnt=0;
    int ca=0,cb=0;
    for(i=1;i<=n;++i)
    {
        if(ca!=v[i])
        {
            ++cnt;
            if(cb!=ca && cb!=v[i])
                cb=0;
            ca=v[i];
        }
        else
        {
            if(cb!=v[i])
            {
                cb=v[i];
                ++cnt;
            }
        }
    }
    cout<<cnt;
    return 0;
}