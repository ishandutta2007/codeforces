
#include <bits/stdc++.h>

using namespace std;

/*
long long mod = 1000000007;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int lsb (int x)
{
    return x&-x;
}
vector<int>ys[3][400003];
vector<int>aib[3][400003];
void preupdate (int id, int a, int b)
{
    for(int i=a;i<=400000;i+=lsb(i))
        ys[id][i].push_back(b);
}
void preprocess (int id)
{
    for(int i=1;i<=400000;++i)
    {
        sort(ys[id][i].begin(),ys[id][i].end());
        aib[id][i].resize(ys[id][i].size()+1,0);
    }
}
void upd (int id, int a, int b, int val)
{
    for(int i=a;i<=400000;i+=lsb(i))
    {
        int j=lower_bound(ys[id][i].begin(),ys[id][i].end(),b)-ys[id][i].begin()+1;
        for(;j<aib[id][i].size();j+=lsb(j))
            aib[id][i][j]+=val;
    }
}
int qry (int id, int a, int b)
{
    int rz=0;
    for(int i=a;i>=1;i-=lsb(i))
    {
        int j=upper_bound(ys[id][i].begin(),ys[id][i].end(),b)-ys[id][i].begin()+1-1;
        for(;j>=1;j-=lsb(j))
            rz+=aib[id][i][j];
    }
    return rz;
}
int a[200003],b[200003];
map<int,int>mp[400003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,k,n;
    //mp[2][3]=1;
    cin>>n>>m>>q;
    for(i=1;i<=q;++i)
    {
        cin>>a[i]>>b[i];
        if(a[i]%2==0)
            preupdate(1,a[i],b[i]);
        else
            preupdate(2,a[i],b[i]);
    }
    preprocess(1);
    preprocess(2);
    long long cnt=0;
    for(i=1;i<=q;++i)
    {
        long long coef=1;
        mp[a[i]][b[i]]=1-mp[a[i]][b[i]];
        if(mp[a[i]][b[i]]==0)
            coef=-1;
        if(a[i]%2==0)
        {
            cnt=cnt+coef*1LL*qry(2,a[i],b[i]);
            upd(1,a[i],b[i],coef);
        }
        else
        {
            cnt=cnt+coef*1LL*(qry(1,400000,400000)-qry(1,a[i]-1,400000)-qry(1,400000,b[i]-1)+qry(1,a[i]-1,b[i]-1));
            upd(2,a[i],b[i],coef);
        }
        if(cnt==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}