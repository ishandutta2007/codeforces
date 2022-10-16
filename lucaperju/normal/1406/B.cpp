#include <bits/stdc++.h>
using namespace std;
long long v[100005];
bool cmp (int a, int b)
{
    int ca=a,cb=b;
    if(ca<0)
        ca=-ca;
    if(cb<0)
        cb=-cb;
    return ca>cb;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        if(v[n]<=0 || n==5)
        {
            if(v[n]==0)
                cout<<0<<'\n';
            else
                cout<<v[n]*1LL*v[n-1]*v[n-2]*v[n-3]*v[n-4]<<'\n';
            continue;
        }
        sort(v+1,v+n+1,cmp);
        long long rz=-10000000000000000LL;
        for(int catpoz=1;catpoz<=5;catpoz+=2)
        {
            long long rzc=1;
            int cntc=catpoz;
            for(i=1;i<=n && cntc;++i)
                if(v[i]>0)
                {
                    --cntc;
                    rzc*=v[i];
                }
            if(cntc)
                continue;
            cntc=5-catpoz;
            for(i=1;i<=n && cntc;++i)
                if(v[i]<=0)
                {
                    --cntc;
                    rzc*=v[i];
                }
            if(cntc)
                continue;
            rz=max(rz,rzc);
        }
        cout<<rz<<'\n';
    }
    return 0;
}