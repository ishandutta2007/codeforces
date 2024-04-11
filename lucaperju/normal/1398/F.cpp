#include <bits/stdc++.h>
using namespace std;
int vc[1000006];
int v[2000006];
int fel[2000006];
vector<int> pzc;
vector<int> candad[1000006];
vector<int> aux;
int rz[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,d,i,j,t;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        char c;
        cin>>c;
        if(c=='?')
            vc[i]=-1;
        else
            vc[i]=c-'0';
    }
    int cnt1=0,cnt0=0;
    for(i=1;i<=n;++i)
    {
        if(vc[i]==1)
            ++cnt1;
        if(vc[i]==0)
            ++cnt0;
    }
    if(cnt1==0 || cnt0==0)
    {
        for(i=1;i<=n;++i)
            cout<<n/i<<' ';
        return 0;
    }
    for(i=1;i<=n;++i)
        if(vc[i]!=-1)
            break;
    for(j=1;j<=i;++j)
        vc[j]=vc[i];
    for(i=n;i>=1;--i)
        if(vc[i]!=-1)
            break;
    for(j=n;j>=i;--j)
        vc[j]=vc[i];
    for(i=1;i<=n;++i)
    {
        if(vc[i]==-1 && vc[i-1]!=-1)
        {
            for(j=i;j<=n;++j)
                if(vc[j]!=-1)
                    break;
            if(vc[i-1]==vc[j])
            {
                for(;j>=i;--j)
                    vc[j]=vc[i-1];
            }
        }
    }
    int vr=vc[1];
    int prec;
    int cnt=0;
    j=0;
    for(i=1;i<=n;++i)
    {
        if(vc[i]==vr)
            ++cnt;
        else
        {
            v[++j]=cnt;
            fel[j]=vr;
            if(vr!=-1)
            {
                prec=vr;
                vr=-1;
            }
            else
                vr=1-prec;
            if(vc[i]!=vr)
            {
                v[++j]=0;
                fel[j]=vr;
                if(vr!=-1)
                {
                    prec=vr;
                    vr=-1;
                }
                else
                    vr=1-prec;
            }
            cnt=1;
        }
    }
    v[++j]=cnt;
    int ni=n;
    n=j;
    for(i=1;i<=n;++i)
    {
        if(i>=2)
            candad[max(max(v[i]+v[i-1]+v[i-2],v[i-1]+v[i]+v[i+1]),v[i]+v[i+1]+v[i+2])].push_back(i);
        else
            candad[max(v[i]+v[i+1]+v[i+2],v[i]+v[i-1]+v[i+1])].push_back(i);
    }
    for(int k=ni;k>=1;--k)
    {
        aux.clear();
        for(i=0;i<pzc.size();++i)
            aux.push_back(pzc[i]);
        pzc.clear();
        int i=0,j=0;
        while(i<candad[k].size() || j<aux.size())
        {
            if(i<candad[k].size() && j<aux.size())
            {
                if(candad[k][i]<aux[j])
                {
                    pzc.push_back(candad[k][i]);
                    ++i;
                }
                else
                {
                    pzc.push_back(aux[j]);
                    ++j;
                }
            }
            else if(i<candad[k].size())
            {
                pzc.push_back(candad[k][i]);
                ++i;
            }
            else
            {
                pzc.push_back(aux[j]);
                ++j;
            }
        }
        int ram=0;
        for(i=0;i<pzc.size();++i)
        {
            if(i>0 && pzc[i]!=pzc[i-1]+1)
                ram=0;
            int vlc=v[pzc[i]];
            int flc=fel[pzc[i]];
            if(flc==-1)
            {
                if(vlc+ram>=k)
                {
                    vlc-=(k-ram);
                    ++rz[k];
                }
                rz[k]+=vlc/k;
                ram=vlc%k;
            }
            else
            {
                vlc+=ram;
                rz[k]+=vlc/k;
                ram=vlc%k;
            }
        }
    }
    for(i=1;i<=ni;++i)
        cout<<rz[i]<<' ';
    return 0;
}