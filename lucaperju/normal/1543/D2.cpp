#include <bits/stdc++.h>
using namespace std;
int v[103][20];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long k,m=0,i,j,n,l,r,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<=k;++i)
            for(j=0;j<=18;++j)
                v[i][j]=i;
        for(i=0;i<n;++i)
        {
            int ci=i;
            int s=0,cntc=0,kc=1;
            while(ci>0)
            {
                int vlc=v[ci%k][cntc];
                s+=vlc*kc;
                ci/=k;
                kc=kc*k;
                ++cntc;
            }
            ci=i;
            for(j=0;j<=18;++j)
            {
                int vlc=v[ci%k][j];
                ci/=k;
                for(int x=0;x<k;++x)
                    v[x][j]=(vlc-v[x][j]+k)%k;
            }
            cout<<s<<'\n';
            cout.flush();
            int a;
            cin>>a;
            if(a)
                break;
        }
    }
    return 0;
}