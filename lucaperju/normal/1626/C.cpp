
#include <bits/stdc++.h>
using namespace std;
long long pz[103],v[103],st[103];
long long cat[103];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>pz[i];
        for(i=1;i<=n;++i)
            cin>>v[i];
        long long s=0;
        k=0;
        for(i=1;i<=n;++i)
        {
            while(k>0 && v[st[k]]-pz[st[k]]<=v[i]-pz[i])
                --k;
            st[++k]=i;
        }
        long long lst=0,ok=0;
        for(i=1;i<=k;++i)
        {
            int pzc=st[i];
            if(pz[pzc]-pz[st[i-1]]>=v[pzc])
                cat[i]=v[pzc],s=s+(v[pzc]*1LL*(v[pzc]+1LL))/2LL;
            else
                cat[i]=cat[i-1]+pz[pzc]-pz[st[i-1]],s=s-(cat[i-1]*1LL*(cat[i-1]+1LL))/2LL+(cat[i]*1LL*(cat[i]+1LL))/2LL;
        }
        cout<<s<<'\n';
    }
    return 0;
}