#include <bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long u,m,ok=0,i,j=0,cnt=0,s=0,h,l,r,t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        for(i=1;i<=n;++i)
            if(v[i]!=v[i-1])
                ++cnt;
        cout<<cnt<<'\n';
    }
    return 0;
}