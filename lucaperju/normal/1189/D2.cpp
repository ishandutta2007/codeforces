#include <bits/stdc++.h>

using namespace std;
vector <int> v[1003];
int k=0;
int getleaf (int pz, int t)
{
    if(v[pz].size()==1)
        return pz;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]!=t)
        {
            return getleaf(v[pz][i],pz);
        }
    }
}
int rza[40003],rzb[40003],rzc[40003];
int ai[1003],bi[1003],ci[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,j,sc=0;
    cin>>n;
    for(i=1;i<n;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);
        ai[i]=a;
        bi[i]=b;
        ci[i]=c;
        //cst[a][b]=cst[b][a]=c;
    }
    int ok=1;
    for(i=1;i<=n;++i)
    {
        if(v[i].size()==2)
            ok=0;
    }
    if(ok)
        cout<<"YES\n";
    else
    {
        cout<<"NO";
        return 0;
    }
    for(i=1;i<n;++i)
    {
        int a=ai[i];
        int b=bi[i];
        int cst=ci[i];
        if(v[a].size()==1 && v[b].size()==1)
        {
            rza[++k]=a;
            rzb[k]=b;
            rzc[k]=cst;
            continue;
        }
        int fa1=0,fa2=0,fb1=0,fb2=0;
        if(v[a].size()!=1)
        {
            for(int i=0;i<v[a].size();++i)
            {
                if(v[a][i]!=b)
                {
                    if(!fa1)
                        fa1=v[a][i];
                    else if (!fa2)
                        fa2=v[a][i];
                    else
                        break;
                }
            }
        }
        if(v[b].size()!=1)
        {
            for(int i=0;i<v[b].size();++i)
            {
                if(v[b][i]!=a)
                {
                    if(!fb1)
                        fb1=v[b][i];
                    else if (!fb2)
                        fb2=v[b][i];
                    else
                        break;
                }
            }
        }
        if(v[a].size()==1)
        {
            rza[++k]=a;
            rzb[k]=getleaf(fb1,b);
            rzc[k]=cst/2;
            rza[++k]=a;
            rzb[k]=getleaf(fb2,b);
            rzc[k]=cst/2;
            rza[++k]=getleaf(fb2,b);
            rzb[k]=getleaf(fb1,b);
            rzc[k]=-cst/2;
            continue;
        }
        if(v[b].size()==1)
        {
            rza[++k]=b;
            rzb[k]=getleaf(fa1,a);
            rzc[k]=cst/2;
            rza[++k]=b;
            rzb[k]=getleaf(fa2,a);
            rzc[k]=cst/2;
            rza[++k]=getleaf(fa2,a);
            rzb[k]=getleaf(fa1,a);
            rzc[k]=-cst/2;
            continue;
        }
        rza[++k]=getleaf(fa1,a);
        rzb[k]=getleaf(fb1,b);
        rzc[k]=cst/2;
        rza[++k]=getleaf(fa2,a);
        rzb[k]=getleaf(fb2,b);
        rzc[k]=cst/2;
        rza[++k]=getleaf(fa1,a);
        rzb[k]=getleaf(fa2,a);
        rzc[k]=-cst/2;
        rza[++k]=getleaf(fb2,b);
        rzb[k]=getleaf(fb1,b);
        rzc[k]=-cst/2;
    }
    cout<<k<<'\n';
    for(i=1;i<=k;++i)
        cout<<rza[i]<<' '<<rzb[i]<<' '<<rzc[i]<<'\n';
    return 0;
}