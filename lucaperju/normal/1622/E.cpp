#include <bits/stdc++.h>

using namespace std;


struct ura
{
    int val,pz;
};
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int rzc[10004];
int v[10005];
int v1[15][10003]; /// muie
ura vc[10004];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,n,k,s=0,t,i,j,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                char c;
                cin>>c;
                v1[i][j]=c-'0';
            }
        long long rz=0;
        long long rzm=0;
        for(int mask=0;mask<(1<<n);++mask)
        {
            int cm=mask;
            for(i=1;i<=m;++i)
                vc[i]={0,i};
            for(i=1;i<=n;++i)
            {
                for(j=1;j<=m;++j)
                {
                    if(v1[i][j])
                    {
                        if(cm&1)
                            ++vc[j].val;
                        else
                            --vc[j].val;
                    }
                }
                cm>>=1;
            }
            sort(vc+1,vc+m+1,cmp);
            for(i=1;i<=m;++i)
                rzc[vc[i].pz]=i;
            s=0;
            for(i=1;i<=n;++i)
            {
                int sc=0;
                for(j=1;j<=m;++j)
                    if(v1[i][j])
                        sc+=rzc[j];
                s=s+max(sc-v[i],v[i]-sc);
            }
            if(s>rz)
                rzm=mask,rz=s;
        }
        int mask=rzm;
        int cm=mask;
            for(i=1;i<=m;++i)
                vc[i]={0,i};
            for(i=1;i<=n;++i)
            {
                for(j=1;j<=m;++j)
                {
                    if(v1[i][j])
                    {
                        if(cm&1)
                            ++vc[j].val;
                        else
                            --vc[j].val;
                    }
                }
                cm>>=1;
            }
            sort(vc+1,vc+m+1,cmp);
            for(i=1;i<=m;++i)
                rzc[vc[i].pz]=i;
        for(i=1;i<=m;++i)
            cout<<rzc[i]<<' ';
        cout<<'\n';
    }
}