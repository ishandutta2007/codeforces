#include <bits/stdc++.h>

using namespace std;

long long v[200005];
long long sp[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,k,s=0,t,i,j,m;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        for(i=1;i<=n;++i)
            sp[i]=v[i]+sp[i-1];
        long long rz=max(sp[n]-k,0LL);
        for(i=n;i>1;--i)
        {
            long long sc=sp[i-1]+(n-i+1)*1LL*v[1];
            long long scad=n-i+2;
            long long dif=sc-k;
            if(dif<=0LL)
                rz=min(rz,n-i+1);
            else
                rz=min(rz,n-i+1LL+max(0LL,(dif-1LL)/scad+1LL));
        }
        cout<<rz<<'\n';
    }
}