#include <bits/stdc++.h>
#define inf (999999999)
using namespace std;
int cst[10010007],h[10010007],n,m,k,g,r,rz=inf;
bool viz[10010007];
int vec[10004];
int convert (int i, int k)
{
    return (i-1)*g+k;
}
int getk (int val)
{
    return (val-1)%g+1;
}
int geti (int val)
{
    return (val-1)/g+1;
}
void shift_up (int poz)
{
    while(poz>1 && cst[h[poz]]<cst[h[poz/2]])
    {
        swap(h[poz],h[poz/2]);
        poz>>=1;
    }
}
void shift_down (int poz)
{
    while(poz*2<k && cst[h[poz]]>min(cst[h[poz*2]],cst[h[poz*2+1]]))
    {
        if(cst[h[poz*2]]<cst[h[poz*2+1]])
        {
            swap(h[poz],h[poz*2]);
            poz<<=1;
        }
        else
        {
            swap(h[poz],h[poz*2+1]);
            poz<<=1;
            ++poz;
        }
    }
    if(poz*2==k && cst[h[poz]]>cst[h[poz*2]])
        swap(h[poz],h[poz*2]);
}
void dijkstra ()
{
    int nc,nn,i;
    nc=convert(1,g);
    viz[nc]=1;
    h[++k]=nc;
    cst[nc]=0;
    while(k)
    {
        nc=h[1];
        swap(h[1],h[k]);
        --k;
        shift_down(1);
        viz[nc]=0;
        if(geti(nc)==n)
        {
            rz=min(rz,cst[nc]);
            if(getk(nc)==g)
                rz=min(rz,cst[nc]-r);
        }
       /* for(i=0;i<v[nc].size();++i)
        {
            nn=v[nc][i];
            if(cst[nn]>cst[nc]+co[nc][i])
            {
                cst[nn]=cst[nc]+co[nc][i];
                if(!viz[nn])
                {
                    h[++k]=nn;
                    shift_up(k);
                    viz[nn]=1;
                }
            }
        }*/
        int ic=geti(nc);
        int kc=getk(nc);
        if(ic!=1)
        {
            int dst=vec[ic]-vec[ic-1];
            int newk=kc-dst;
            if(newk==0)
                newk+=g;
            if(dst<=kc)
            {
                nn=convert(ic-1,newk);
                if(kc-dst==0)
                    dst+=r;
                int co=dst;
                if(cst[nn]>cst[nc]+co)
                {
                    cst[nn]=cst[nc]+co;
                    if(!viz[nn])
                    {
                        h[++k]=nn;
                        shift_up(k);
                        viz[nn]=1;
                    }
                }
            }
        }
        if(ic!=n)
        {
            int dst=vec[ic+1]-vec[ic];
            int newk=kc-dst;
            if(newk==0)
                newk+=g;
            if(dst<=kc)
            {
                nn=convert(ic+1,newk);
                if(kc-dst==0)
                    dst+=r;
                int co=dst;
                if(cst[nn]>cst[nc]+co)
                {
                    cst[nn]=cst[nc]+co;
                    if(!viz[nn])
                    {
                        h[++k]=nn;
                        shift_up(k);
                        viz[nn]=1;
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,i,j;
    cin>>n>>n;
    for(i=1;i<=n;++i)
        cin>>vec[i];
    sort(vec+1,vec+n+1);
    cin>>g>>r;
    for(i=1;i<=n;++i)
    {
        for(k=1;k<=g;++k)
        {
        /*    if(i!=1)
            {
                int dst=vec[i]-vec[i-1];
                int newk=k-dst;
                if(newk==0)
                    newk+=g;
                if(dst<=k)
                    v[convert(i,k)].push_back(convert(i-1,newk));
                if(k-dst==0)
                    dst+=r;
                if(newk>0)
                    co[convert(i,k)].push_back(dst);
            }
            if(i!=n)
            {
                int dst=vec[i+1]-vec[i];
                int newk=k-dst;
                if(newk==0)
                    newk+=g;
                if(dst<=k)
                    v[convert(i,k)].push_back(convert(i+1,newk));
                if(k-dst==0)
                    dst+=r;
                if(newk>0)
                    co[convert(i,k)].push_back(dst);
            }*/
            cst[convert(i,k)]=inf;
        }
    }
    k=0;
    dijkstra();
    if(rz==inf)
        cout<<-1;
    else
        cout<<rz;
    return 0;
}