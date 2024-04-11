#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,fv[200005],q[200005],bfs[200005];
vector <int> v[200005];
void citire ()
{
    int i,a,b;
    cin>>n;
    for(i=1;i<n;++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}
bool rez ()
{
    int poz,nc,i,j,st=1,dr=0;
    for(i=1;i<=n;++i)
        cin>>bfs[i];
    for(j=n;j>=1;--j)
    {
        nc=bfs[j];
        poz=-1;
        fv[nc]=1;
        for(i=0;i<v[nc].size();++i)
            if(fv[v[nc][i]]==0)
                if(poz==-1)
                    poz=v[nc][i];
                else
                    return false;
        if(nc==q[st])
            ++st;
        if(q[dr]!=poz && poz!=-1)
            q[++dr]=poz;
    }
    if(st<=dr || bfs[1]!=1)
        return false;
    return true;
}
/*long long cmmdc(long long a,long long b)
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
    else
    if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}*/
int main()
{
   // long long t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,s=0,k,x,y,z,ok=1,cur,cn,cnt=0,q;
   // char c;
    citire();
    if(rez())
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}