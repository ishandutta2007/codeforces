#include <bits/stdc++.h>

using namespace std;
int fv[1003];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j,cnt=0,k=0,mn=2,n,m,is,js,ib,jb;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        ++fv[a];
    }
    for(i=1;i<=k;++i)
    {
        if(fv[i]%2)
            ++cnt;
    }
    cout<<n-cnt/2;
    return 0;
}