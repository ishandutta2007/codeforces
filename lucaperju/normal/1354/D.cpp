#include <bits/stdc++.h>

using namespace std;
int aib[1000006],n;
int lsb (int x)
{
    return x&-x;
}
void update (int pz, int val)
{
    for(int i=pz;i && i<=n;i+=lsb(i))
        aib[i]+=val;
}
void scoate(int k)
{
    int pas=1<<20;
    int pz=0;
    --k;
    while(pas)
    {
        if(pz+pas<=n && aib[pz+pas]<=k)
        {
            pz+=pas;
            k-=aib[pz];
        }
        pas>>=1;
    }
    update(pz+1,-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long i,m,t,j,k,mx,p,mxx=0,s,q;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        update(a,1);
    }
    for(i=1;i<=m;++i)
    {
        int a;
        cin>>a;
        if(a>0)
            update(a,1);
        else
            scoate(-a);
    }
    for(i=1;i<=n;++i)
        if(aib[i])
        {
            cout<<i;
            return 0;
        }
    cout<<0;
    return 0;
}