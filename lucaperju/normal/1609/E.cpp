#include <bits/stdc++.h>

using namespace std;


/*
const long long mod = 998244353;

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
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
char v[100005];
struct ura
{
    int dp[3][3];
};
ura aint[400005];
ura join (ura a, ura b)
{
    ura ans;
    for(int l=0;l<=2;++l)
        for(int r=l;r<=2;++r)
        {
            ans.dp[l][r]=1000000;
            for(int mid=l;mid<=r;++mid)
                ans.dp[l][r]=min(ans.dp[l][r],a.dp[l][mid]+b.dp[mid][r]);
            for(int mid=l;mid+1<=r;++mid)
                ans.dp[l][r]=min(ans.dp[l][r],a.dp[l][mid]+b.dp[mid+1][r]);
            for(int mid=l;mid+2<=r;++mid)
                ans.dp[l][r]=min(ans.dp[l][r],a.dp[l][mid]+b.dp[mid+2][r]);
        }
    return ans;
}
void upd (int nod, int l, int r, int pz)
{
    if(l==r)
    {
        for(int i=0;i<=2;++i)
            for(int j=i;j<=2;++j)
                aint[nod].dp[i][j]=1000000;
        aint[nod].dp[0][0]=aint[nod].dp[1][1]=aint[nod].dp[2][2]=0;
        aint[nod].dp[v[pz]-'a'][v[pz]-'a']=1;
        return;
    }
    int mid=(l+r)/2;
    if(pz<=mid)
        upd(nod<<1,l,mid,pz);
    else
        upd((nod<<1)|1,mid+1,r,pz);
    aint[nod]=join(aint[nod<<1],aint[(nod<<1)|1]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,k,j,n;
    cin>>n>>q;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
        upd(1,1,n,i);
    for(i=1;i<=q;++i)
    {
        int pz;
        char c;
        cin>>pz>>c;
        v[pz]=c;
        upd(1,1,n,pz);
        int mn=100000;
        for(int l=0;l<=2;++l)
            for(int r=l;r<=2;++r)
                mn=min(mn,aint[1].dp[l][r]);
        cout<<mn<<'\n';
    }
    return 0;
}