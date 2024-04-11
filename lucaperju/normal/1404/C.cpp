#include <bits/stdc++.h>
using namespace std;
int v[300005];
int aib[300005],n;
int lsb (int x)
{
    return x&-x;
}
int rz[300005];
vector<int>st[300005];
vector<int>pz[300005];
int query (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
void update (int pz, int val)
{
    for(int i=pz;i<=n;i+=lsb(i))
        aib[i]+=val;
}
int cautbin (int val)
{
    int pz=0;
    int pas=1<<20,sc=0;
    while(pas)
    {
        if(pz+pas<=n && sc+aib[pz+pas]>=val)
        {
            pz+=pas;
            sc+=aib[pz];
        }
        pas>>=1;
    }
    return pz;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k,q;
    cin>>n>>q;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=q;++i)
    {
        int a,b;
        cin>>a>>b;
        ++a;
        b=n-b;
        st[b].push_back(a);
        pz[b].push_back(i);
    }
    for(i=1;i<=n;++i)
    {
        int dst=i-v[i];
        if(dst>=0)
        {
            int pzc=cautbin(dst);
            update(1,1);
            update(min(i+1,pzc+1),-1);
        }
        for(j=0;j<st[i].size();++j)
        {
            int a=st[i][j];
            int pzc=pz[i][j];
            rz[pzc]=query(a);
        }
    }
    for(i=1;i<=q;++i)
        cout<<rz[i]<<'\n';
}