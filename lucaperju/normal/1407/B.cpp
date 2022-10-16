#include <bits/stdc++.h>
using namespace std;
int v[10003];
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,i,j,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int mx=0;
        for(i=1;i<=n;++i)
            mx=max(mx,v[i]);
        int gcdc=mx;
        for(i=1;i<=n;++i)
        {
            int mx=0;
            int pz=1;
            for(j=1;j<=n;++j)
            {
                if(v[j]==-1)
                    continue;
                int valc=cmmdc(gcdc,v[j]);
                if(valc>mx)
                {
                    mx=valc;
                    pz=j;
                }
            }
            gcdc=mx;
            cout<<v[pz]<<' ';
            v[pz]=-1;
        }
        cout<<'\n';
    }
    return 0;
}