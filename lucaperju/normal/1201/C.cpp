#include <bits/stdc++.h>

using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j=0,cnt=1,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b,st,dr,mx=0,cur=0;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    cur=v[n/2+1];
    for(i=n/2+2;i<=n;++i)
    {
        if((v[i]-cur)*cnt<=k)
        {
            k-=(v[i]-cur)*cnt;
            ++cnt;
            cur=v[i];
        }
        else
        {
            cout<<cur+k/cnt;
            return 0;
        }
    }
    cout<<cur+k/cnt;
    return 0;
    return 0;
}