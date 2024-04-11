#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
const long long mod=998244353;
vector <int> v[300005];
int okall;
long long put2[300005],cnt1,cnt2,viz[300005];
void dfs (int poz, int val)
{
    viz[poz]=val;
    if(val==1)
        ++cnt1;
    else
        ++cnt2;
    int vln=3-val;
    for(int i=0;i<v[poz].size();++i)
    {
        int nn=v[poz][i];
        if(viz[nn] && viz[nn]!=vln)
            okall=1;
        if(!viz[nn])
            dfs(nn,vln);
    }
}
int main()
{
    long long t,n,i,j=0,k=0,s=1,okneg=0,cnt=0,mn=99999999999999LL,m,cur=0,pz,a,b,vl1=1,ok,sus=1,jos=1;
    j=1;
    put2[0]=1;
    for(i=1;i<=300000;++i)
    {
        j=j*2LL;
        j%=mod;
        put2[i]=j;
    }
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        okall=0;
        s=1;
        for(i=1;i<=n;++i)
            viz[i]=0;
        for(i=1;i<=m;++i)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=1;i<=n;++i)
        {
            if(!viz[i])
            {
                cnt1=cnt2=0;
                dfs(i,1);
                cur=put2[cnt1]+put2[cnt2];
                cur%=mod;
                s=s*1LL*cur;
                s%=mod;
            }
        }
        if(okall)
            cout<<0<<'\n';
        else
            cout<<s<<'\n';
        for(i=1;i<=n;++i)
            v[i].clear();
    }
}