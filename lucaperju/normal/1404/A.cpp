#include <bits/stdc++.h>
using namespace std;
char v[300005];
int vc[300005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,t,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>(v+1);
        for(i=1;i<=k;++i)
            vc[i]=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]=='0')
            {
                int pz=(i-1)%k+1;
                if(vc[pz]==1)
                    break;
                vc[pz]=-1;
            }
            if(v[i]=='1')
            {
                int pz=(i-1)%k+1;
                if(vc[pz]==-1)
                    break;
                vc[pz]=1;
            }
        }
        if(i<=n)
        {
            cout<<"NO\n";
            continue;
        }
        int sum1=0,sum0=0;
        for(i=1;i<=k;++i)
        {
            if(vc[i]==1)
                ++sum1;
            if(vc[i]==-1)
                ++sum0;
        }
        if(max(sum1,sum0)>k/2)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}