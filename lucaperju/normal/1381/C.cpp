#include <bits/stdc++.h>
using namespace std;
int v[100005];
int fv[100005];
int vf[100005];
int ocp[100005];
int ocpfv[100005];
vector<int>pzc;
struct ura
{
    int pz,val;
}vc[100005];
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        pzc.clear();
        int cnt=0;
        int mx=0,val;
        for(i=1;i<=n+1;++i)
        {
            fv[i]=0;
            ocp[i]=0;
            ocpfv[i]=0;
        }
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            ++fv[v[i]];
            if(fv[v[i]]==1)
                ++cnt;
            if(fv[v[i]]>mx)
            {
                mx=fv[v[i]];
                val=v[i];
            }
        }
        int nul;
        for(i=1;i<=n+1;++i)
            if(fv[i]==0)
                nul=i;
        int sz=y-x;
        for(i=1;i<=n;++i)
            vf[i]=v[i];
        if(sz%2==0)
        {
            if(n-mx>=sz/2)
                cout<<"YES\n";
            else
            {
                cout<<"NO\n";
                continue;
            }
            pzc.clear();
            int cntc=sz/2;
            for(i=1;i<=n && cntc;++i)
            {
                if(v[i]==val)
                {
                    pzc.push_back(i);
                    --cntc;
                    ocp[i]=1;
                }
            }
            cntc+=sz/2;
            for(i=1;i<=n && cntc;++i)
            {
                if(v[i]!=val)
                {
                    pzc.push_back(i);
                    --cntc;
                    ocp[i]=1;
                }
            }
            int mxc=min(mx,sz/2);
            for(i=0;i<pzc.size();++i)
                vc[i+1]={pzc[i],v[pzc[i]]};
            sort(vc+1,vc+sz+1,cmp);
            for(i=1;i<=sz;++i)
            {
                int pzn=i;
                pzn-=mxc;
                if(pzn<1)
                    pzn+=sz;
                vf[vc[i].pz]=vc[pzn].val;
            }
            cntc=n-y;
            for(i=1;i<=n && cntc;++i)
            {
                if(!ocp[i])
                {
                    vf[i]=nul;
                    --cntc;
                }
            }
            for(i=1;i<=n;++i)
                cout<<vf[i]<<' ';
            cout<<'\n';
        }
        else
        {
            if(cnt==1)
            {
                cout<<"NO\n";
                continue;
            }
            if(n-mx<=sz/2)
            {
                cout<<"NO\n";
                continue;
            }
            if(cnt==2)
            {
                if(y==n)
                {
                    cout<<"NO\n";
                    continue;
                }
                cout<<"YES\n";
                int cntc=sz/2+1;
                for(i=1;i<=n && cntc;++i)
                {
                    if(v[i]==val)
                    {
                        pzc.push_back(i);
                        --cntc;
                        ocp[i]=1;
                    }
                }
                cntc=sz/2+1;
                int pzs;
                int val1;
                for(i=1;i<=n && cntc;++i)
                {
                    if(v[i]!=val)
                    {
                        val1=v[i];
                        if(cntc==1)
                        {
                            pzs=i;
                            ocp[i]=1;
                            break;
                        }
                        pzc.push_back(i);
                        --cntc;
                        ocp[i]=1;
                    }
                }
                for(i=0;i<pzc.size();++i)
                    vf[pzc[i]]=val+val1-vf[pzc[i]];
                vf[pzs]=val;
                vf[pzc[0]]=nul;
                cntc=n-y-1;
                for(i=1;i<=n && cntc;++i)
                {
                    if(!ocp[i])
                    {
                        vf[i]=nul;
                        --cntc;
                    }
                }
                for(i=1;i<=n;++i)
                    cout<<vf[i]<<' ';
                cout<<'\n';
                continue;
            }
            if(sz==1)
            {
                if(y==n)
                {
                    cout<<"NO\n";
                    continue;
                }
                cout<<"YES\n";
                for(i=1;i<=n;++i)
                    if(v[i]!=v[1])
                        break;
                ocp[1]=ocp[i]=1;
                vf[1]=nul;
                vf[i]=v[1];
                int cntc=n-y-1;
                for(i=1;i<=n && cntc;++i)
                {
                    if(!ocp[i])
                    {
                        vf[i]=nul;
                        --cntc;
                    }
                }
                for(i=1;i<=n;++i)
                    cout<<vf[i]<<' ';
                cout<<'\n';
                continue;
            }
            cout<<"YES\n";
            int cntc=sz/2;
            for(i=1;i<=n && cntc;++i)
            {
                if(v[i]==val)
                {
                    pzc.push_back(i);
                    --cntc;
                    ocp[i]=1;
                    ocpfv[v[i]]=1;
                }
            }
            cntc+=sz/2;
            for(i=1;i<=n && cntc;++i)
            {
                if(v[i]!=val)
                {
                    pzc.push_back(i);
                    --cntc;
                    ocp[i]=1;
                    ocpfv[v[i]]=1;
                }
            }
            for(i=1;i<=n;++i)
                if(!ocpfv[v[i]])
                {
                    pzc.push_back(i);
                    ocp[i]=1;
                    break;
                }
            if(i==n+1)
            {
                for(i=1;i<=n;++i)
                {
                    if(v[i]!=val && !ocp[i])
                    {
                        pzc.push_back(i);
                        ocp[i]=1;
                        break;
                    }
                }
            }
            int mxc=min(mx,sz/2);
            for(i=0;i<pzc.size();++i)
                vc[i+1]={pzc[i],v[pzc[i]]};
            sort(vc+1,vc+sz+1,cmp);
            for(i=1;i<=sz;++i)
            {
                int pzn=i;
                pzn-=mxc;
                if(pzn<1)
                    pzn+=sz;
                vf[vc[i].pz]=vc[pzn].val;
            }
            cntc=n-y;
            for(i=1;i<=n && cntc;++i)
            {
                if(!ocp[i])
                {
                    vf[i]=nul;
                    --cntc;
                }
            }
            for(i=1;i<=n;++i)
                cout<<vf[i]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}