#include <bits/stdc++.h>
using namespace std;
int v[1000006];
int fv[1000006];
int sp[1000006];
int idk[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
        {
            char a;
            cin>>a;
            a-='0';
            a=1-a;
            v[i]=a;
            fv[i]=0;
            sp[i]=sp[i-1]+v[i];
        }
        fv[0]=0;
        long long vlc=0,pc=1;
        for(i=k;i<=n;++i)
        {
            if(i-21>i-k && sp[i-21]-sp[i-k])
                continue;
            vlc=0,pc=1;
            for(j=i;j>max(i-k,i-21);--j)
            {
                vlc+=v[j]*pc;
                pc<<=1LL;
            }
            if(vlc<=n)
                fv[vlc]=1;
        }
        int pz=-1;
        if(k<=21){
        for(i=0;i<=min(n,(1LL<<k)-1);++i)
            if(fv[i]==0)
            {
                pz=i;
                break;
            }
        }
        else
        {
            for(i=0;i<=n;++i)
            if(fv[i]==0)
            {
                pz=i;
                break;
            }
        }
        if(pz==-1)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(i=1;i<=k;++i)
            {
                idk[i]=(pz&1);
                pz>>=1;
            }
            for(i=k;i>=1;--i)
                cout<<idk[i];
            cout<<'\n';
        }
    }
    return 0;
}