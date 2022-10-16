#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct ura
{
    int a,b;
};
int v[300003];
int fv[1000003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n,i,j,k=0,m;
    long long x1,y1,x2,y2,pas;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            int rzc=1,cntc=0;
            if((v[i]&1)==0)
            {
                while((v[i]&1)==0)
                {
                    v[i]>>=1;
                    ++cntc;
                }
                if(cntc&1)
                    rzc=2;
            }
            for(j=3;j*j<=v[i];j+=2)
            {
                if(v[i]%j!=0)
                    continue;
                cntc=0;
                while(v[i]%j==0)
                {
                    ++cntc;
                    v[i]/=j;
                }
                if(cntc&1)
                    rzc*=j;
            }
            if(v[i]!=1)
                rzc*=v[i];
            v[i]=rzc;
        }
        int mx=0;
        for(i=1;i<=n;++i)
        {
            ++fv[v[i]];
            mx=max(mx,fv[v[i]]);
        }
        int cnt=0;
        cnt=fv[1];
        for(i=1;i<=n;++i)
        {
            if(v[i]!=1 && fv[v[i]]%2==0)
            {
                cnt+=fv[v[i]];
                fv[v[i]]=0;
            }
        }
        for(i=1;i<=n;++i)
            fv[v[i]]=0;
        int q;
        cin>>q;
        while(q--)
        {
            long long a;
            cin>>a;
            if(a==0)
                cout<<mx<<'\n';
            else
                cout<<max(mx,cnt)<<'\n';
        }
    }
    return 0;
}