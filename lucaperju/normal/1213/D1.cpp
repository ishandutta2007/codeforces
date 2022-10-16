#include <bits/stdc++.h>

using namespace std;
long long v[200005],cst[200005],cat[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,k=0,s=0,cnt=0,m=9999999999LL,t;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
    {
        int pz=v[i];
        cnt=0;
        while(pz>=0)
        {
            if(cat[pz]<k)
                ++cat[pz],cst[pz]+=cnt;
            ++cnt;
            pz>>=1;
            if(pz==0)
                break;
        }
    }
    for(i=0;i<=200005;++i)
        if(cat[i]>=k)
            m=min(m,cst[i]);
    cout<<m;
    return 0;
}