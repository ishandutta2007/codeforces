#include <bits/stdc++.h>
using namespace std;
vector<long long>v[200005];
vector<long long>cst[200005];
vector<long long>cst1[200005];
vector<long long>all1,all2;
long long sall;
long long dfs (long long pz, long long t)
{
    long long sc=0;
    if(v[pz].size()==1)
        ++sc;
    for(long long i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        long long vlc=dfs(v[pz][i],pz);
        long long cstc=cst[pz][i];
        sall+=cstc*1LL*vlc;
        int cstop=cst1[pz][i];
        while(cstc>0)
        {
            ///all.push_back(vlc*1LL*(cstc-cstc/2));
            if(cstop==1)
                all1.push_back(vlc*1LL*(cstc-cstc/2));
            else
                all2.push_back(vlc*1LL*(cstc-cstc/2));
            cstc>>=1;
        }
        sc+=vlc;
    }
    return sc;
}
bool cmp (long long a, long long b)
{
    return a>b;
}
int main()
{
    long long t,n,s,m,i,j,x,y,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        sall=0;
        all1.clear();
        all2.clear();
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            cst[i].clear();
            cst1[i].clear();
        }
        for(i=1;i<n;++i)
        {
            long long a,b,c,d;
            cin>>a>>b>>c>>d;
            v[a].push_back(b);
            v[b].push_back(a);
            cst[a].push_back(c);
            cst[b].push_back(c);
            cst1[a].push_back(d);
            cst1[b].push_back(d);
        }
        dfs(1,-1);
        sort(all1.begin(),all1.end(),cmp);
        sort(all2.begin(),all2.end(),cmp);
        all1.push_back(0);
        for(i=all1.size()-1;i>=1;--i)
            all1[i]=all1[i-1];
        all2.push_back(0);
        for(i=all2.size()-1;i>=1;--i)
            all2[i]=all2[i-1];
        all2[0]=0;
        all1[0]=0;
        for(i=1;i<all2.size();++i)
            all2[i]+=all2[i-1];
        long long rz=9999999999LL;
        s=sall-s;
        long long sc=0,sct=0;
        for(long long cat1=0;cat1<all1.size();++cat1)
        {
            sct+=all1[cat1];
            if(sct>=s)
            {
                rz=min(rz,cat1);
                continue;
            }
            long long k=0;
            long long pas=1LL<<25;
            while(pas)
            {
                if(k+pas<all2.size() && sct+all2[k+pas]<s)
                    k+=pas;
                pas>>=1LL;
            }
            ++k;
            if(k==all2.size())
                continue;
            else
                rz=min(rz,cat1+k*2);
        }
        cout<<rz<<'\n';
    }
    return 0;
}