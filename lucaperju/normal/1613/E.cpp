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
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char v[1000003]; /// ofc fuking n*m<=10^6 instead of n,m<=10^3 bcs why fucking not
int viz[1000003];
int calc(int i, int j)
{
    if(i<1 || n<i || j<1 || m<j)
        return 0;
    return (i-1)*m+j;
}
int getvec (int i, int j)
{
    int cnt=0;
    for(int k=0;k<=3;++k)
        {
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(v[calc(ni,nj)]=='.')
                ++cnt;
        }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i,h,k,j,s=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        queue<pair<int,int> >q;
        v[0]='#';
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                viz[calc(i,j)]=0;
                cin>>v[calc(i,j)];
                if(v[calc(i,j)]=='L')
                    q.push(make_pair(i,j));
            }
        while(!q.empty())
        {
            pair<int,int>pc=q.front();
            q.pop();
            i=pc.first;
            j=pc.second;
            if(v[calc(i,j)]=='.')
                v[calc(i,j)]='+';
            viz[calc(i,j)]=1;
            for(k=0;k<=3;++k)
            {
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(v[calc(ni,nj)]=='#' || viz[calc(ni,nj)] || getvec(ni,nj)>1)
                    continue;
                viz[calc(ni,nj)]=1;
                q.push(make_pair(ni,nj));
            }
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<v[calc(i,j)];
            cout<<'\n';
        }
    }
    return 0;
}