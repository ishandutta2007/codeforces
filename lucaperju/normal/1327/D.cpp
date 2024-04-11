#include <bits/stdc++.h>
using namespace std;
int v[200005],c[200005],viz[200005];
int vc[200005];
int okc[200005];
bool verif (int val,int n)
{
    int i;
    for(i=1;i<=val;++i)
        okc[i]=1;
    for(i=val+1;i<=n;++i)
        okc[i]=min(okc[i-val],(int)(vc[i]==vc[i-val]));
    for(i=n;i>=n-val+1;--i)
        if(okc[i])
            return true;
    return false;
}
int main()
{
    int t,i,j,n,m,cnt=0;
    cin>>t;
    while(t--)
    {
        int mn=300000;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
            cin>>c[i];
        for(i=1;i<=n;++i)
            viz[i]=0;
        for(i=1;i<=n;++i)
        {
            if(!viz[i])
            {
                int cc=c[i];
                int pz=v[i];
                int ok=1;
                int nrpasi=1,cnt=1;
                vc[cnt]=c[i];
                while(pz!=i)
                {
                    ++cnt;
                    vc[cnt]=c[pz];
                    viz[pz]=1;
                    pz=v[pz];
                }
                viz[i]=1;
                for(j=1;j*j<=cnt;++j)
                {
                    if(cnt%j==0)
                    {
                        if(verif(j,cnt))
                        {
                            mn=min(mn,j);
                            break;
                        }
                        if(verif(cnt/j,cnt))
                            mn=min(mn,cnt/j);
                    }
                }
            }
        }
        cout<<mn<<'\n';
    }
    return 0;
}