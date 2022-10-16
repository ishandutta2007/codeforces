#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
/*
for(i=1;i<=n;++i)...
*/
vector <long long> v[1005];
long long viz2[1005],n,m,s,t,q[1005],viz1[1005];
int ad[1002][1002];
void citire ()
{
    cin>>n>>m>>s>>t;
    for(long long i=1;i<=m;++i)
    {
        long long a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        ad[a][b]=ad[b][a]=1;
    }
}
void bfs1 ()
{
    long long st=1,dr=0,nn,nc,i;
    q[++dr]=s;
    viz1[s]=1;
    while(st<=dr)
    {
        nc=q[st];
        for(i=0;i<v[nc].size();++i)
        {
            nn=v[nc][i];
            if(!viz1[nn])
            {
                viz1[nn]=viz1[nc]+1;
                q[++dr]=nn;
            }
        }
        ++st;
    }
}
void bfs2 ()
{
    long long st=1,dr=0,nn,nc,i;
    q[++dr]=t;
    viz2[t]=1;
    while(st<=dr)
    {
        nc=q[st];
        for(i=0;i<v[nc].size();++i)
        {
            nn=v[nc][i];
            if(!viz2[nn])
            {
                viz2[nn]=viz2[nc]+1;
                q[++dr]=nn;
            }
        }
        ++st;
    }
}
/*void dfs (long long poz)
{
    long long val=viz[poz],i,nn;
    viz[poz]=-viz[poz];
    if(val==1)
        return;
    for(i=0;i<v[poz].size();++i)
    {
        nn=v[poz][i];
        if(viz[nn]==val-1)
            dfs(nn);
    }
}*/
void rez ()
{
    long long i,j,a,b,cnt=0,cc,dd;
    if(viz1[t]==n)
    {
        cout<<0;
        return;
    }
    for(i=1;i<=n;++i)
    {
        for(j=i+1;j<=n;++j)
        {
            a=viz1[i];
            b=viz2[j];
            cc=viz1[j];
            dd=viz2[i];
            if(!ad[i][j] && min(a+b,cc+dd)>=viz1[t])
                ++cnt;
        }
    }
    cout<<cnt;
}
int main()
{
    long long i,j,a,b=-1,c,x=1000000000,y,mx=-10000000000,ln,cl,lnp,clp;
    citire();
    bfs1();
    bfs2();
 //   dfs(t);
    rez();
    return 0;
}