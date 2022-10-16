#include <bits/stdc++.h>
using namespace std;
long long v[200005],sp[200005];
int main()
{
    long long t,i,j,n,m,cnt=0;
    long long mn=1000000000000000LL;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        sp[i]=v[i]+sp[i-1];
    v[0]=-1;
    for(i=1;i<=n;)
    {
        if(v[i]!=v[i-1])
        {
            long long st=i;
            for(j=st;j<n && v[j]==v[j+1];++j);
            long long dr=j;
            long long ned=m-(dr-st+1);
            if(ned<=0)
            {
                cout<<0;
                return 0;
            }
            long long catm=st-1;
            long long catM=n-dr;
            long long cstm=(st-1LL)*1LL*(v[st]-1LL)-sp[st-1];
            long long cstM=sp[n]-sp[dr]-(v[st]+1LL)*1LL*(n-dr);
            if(catm>=ned && catM<ned)
            {
                mn=min(mn,ned+cstm);
            }
            if(catM>=ned && catm<ned)
            {
                mn=min(mn,ned+cstM);
            }
            if(catm>=ned && catM>=ned)
            {
                mn=min(mn,ned+min(cstm,cstM));
            }
            if(catm<ned && catM<ned)
            {
                mn=min(mn,ned+cstm+cstM);
            }
            i=j+1;
        }
    }
    cout<<mn;
    return 0;
}