#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
long long cat[100005],cst[100005],d[100005],l[100005],aib_cat[1000003],aib_cst[1000003];
vector <int> v[100005];
long long lsb (long long x)
{
    return x&-x;
}
void dfs (long long poz,long long timp)
{
    timp-=2LL*l[poz];
    if(timp<0)
        return;
    for(long long i=cst[poz];i<=1000000;i+=lsb(i))
    {
        aib_cat[i]+=cat[poz];
        aib_cst[i]+=cat[poz]*1LL*cst[poz];
    }
    long long pz=0,ct=timp;
    for(long long pas=1<<20;pas>0;pas>>=1LL)
        if(pz+pas<=1000000 && ct>=aib_cst[pz+pas])
        {
            ct-=aib_cst[pz+pas];
            pz+=pas;
        }
    for(long long i=pz;i>0;i-=lsb(i))
        d[poz]+=aib_cat[i];
    if(ct<aib_cst[pz+1])
        d[poz]+=ct/(pz+1);
    for(long long i=0;i<v[poz].size();++i)
    {
        int nn=v[poz][i];
        dfs(nn,timp);
    }
    for(long long i=cst[poz];i<=1000000;i+=lsb(i))
    {
        aib_cat[i]-=cat[poz];
        aib_cst[i]-=cat[poz]*1LL*cst[poz];
    }
}
bool verif (long long cat,long long poz)
{
    if(d[poz]>=cat)
        return true;
    int cnt=0;
    for(int i=0;i<v[poz].size();++i)
    {
        int nn=v[poz][i];
        if(verif(cat,nn))
            ++cnt;
    }
    if((cnt && poz==1) || cnt>=2)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    long long ci,cc,i,j,s=0,cnt0,n,a,b,k=0,ok=0,m,mn=30000003,cnt1,cnt,t;
  //  long long aib_cat[10006],aib_cst[10006];
    cin>>n>>t;
    for(i=1;i<=n;++i)
    {
        cin>>cat[i];
        s+=cat[i];
    }
    for(i=1;i<=n;++i)
        cin>>cst[i];
    for(i=2;i<=n;++i)
    {
        cin>>a>>b;
        v[a].push_back(i);
        l[i]=b;
    }
    dfs(1,t);
    long long pas=1LL<<36LL;
    while(pas>0)
    {
        if(k+pas<=s && verif(k+pas,1))
            k+=pas;
        pas>>=1LL;
    }
    cout<<k;
}