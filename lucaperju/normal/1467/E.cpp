#include <bits/stdc++.h>
using namespace std;
int a[200003];
map<int,int>cntt;
map<int,int>cntc;
vector<int>v[200003];
int ok[200003],okt=1;
void fill (int pz, int t)
{
    ok[pz]=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        if(ok[v[pz][i]])
            fill(v[pz][i],pz);
    }
}
int dfs (int pz, int t)
{
    if(!okt)
        return 1;
    int vlc=a[pz];
    int cnt=0,pzc,idk=0,idkpz;
    int prec=cntc[vlc];
    int idk1=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        int valc=dfs(v[pz][i],pz);
        if(valc)
            pzc=i,++cnt;
        if(cntc[vlc]!=prec)
        {
            ++idk;
            idkpz=v[pz][i];
            idk1+=cntc[vlc]-prec;
            prec=cntc[vlc];
        }
    }
    ++cntc[vlc];
    ++idk1;
    if(idk1!=cntt[vlc])
    {
        ++idk;
        idkpz=t;
    }
    if(idk>1)
    {
        okt=0;
        return 1;
    }
    if(cnt>1)
    {
        okt=0;
        return 1;
    }
    if(idk==1 && cnt==1 && idkpz!=v[pz][pzc])
    {
        okt=0;
        return 1;
    }
    if(cnt==1)
    {
        ok[pz]=0;
        for(int i=0;i<v[pz].size();++i)
        {
            if(i!=pzc)
                fill(v[pz][i],pz);
        }
        return 1;
    }
    if(idk==1)
    {
        ok[pz]=0;
        for(int i=0;i<v[pz].size();++i)
        {
            if(v[pz][i]!=idkpz)
                fill(v[pz][i],pz);
        }
        if(idkpz!=t)
            return 1;
        else
            return 0;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k=0,m;
    long long x1,y1,x2,y2,pas;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        ++cntt[a[i]];
        ok[i]=1;
    }
    for(i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    if(okt==0)
    {
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        cnt+=ok[i];
    }
    cout<<cnt;
    return 0;
}