#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
const long long mod=1000000007;
int cntc,viz[100005];
long long lgput (long long cnt,long long put)
{
    long long r=1LL,p=put;
    if(cnt==0)
        return 1;
    else if(cnt<0)
        return 0;
    while(cnt>1){
        if(!(cnt&1)){p=p*1LL*p%mod;cnt>>=1LL;}
        else{--cnt;r=r*1LL*p%mod;}}
    p=p*1LL*r;
    return p%mod;
}
void dfs (int poz)
{
    viz[poz]=1;
    ++cntc;
    for(int i=0;i<v[poz].size();++i)
    {
        int nn=v[poz][i];
        if(!viz[nn])
            dfs(nn);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long h,n,i,j,m,mn=999999999,pz,s=0,y,k=0,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0,mxtot=-1,pzf,sf;
    cin>>n>>k;
    for(i=1;i<n;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c==0)
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    long long rz=lgput(k,n);
    for(i=1;i<=n;++i)
    {
        if(!viz[i])
        {
            cntc=0;
            dfs(i);
            rz=(rz-lgput(k,cntc)+mod)%mod;
        }
    }
    cout<<rz;
    return 0;
}