#include <bits/stdc++.h>

using namespace std;

/*
const int mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(int i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/

int l[251],c[251];

bool cmp (int a, int b)
{
    return a>b;
}
int rz[251][251];
queue<pair<int,int> >q;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            int a;
            cin>>a;
            l[i]=max(l[i],a);
            c[j]=max(c[j],a);
        }
    sort(l+1,l+n+1,cmp);
    sort(c+1,c+m+1,cmp);
    int x=0,y=0,i=1,j=1;
    for(int vlc=n*m;vlc>=1;--vlc)
    {
        int okc=0,okl=0;
        if(l[i]==vlc)
            okl=1,++i;
        if(c[j]==vlc)
            okc=1,++j;
        if(!(okc|okl))
        {
            rz[q.front().first][q.front().second]=vlc;
            q.pop();
            continue;
        }
        if(okl)
            ++x;
        if(okc)
            ++y;
        rz[x][y]=vlc;
        if(okl)
            for(int k=y-1;k>=1;--k)
                q.push(make_pair(x,k));
        if(okc)
            for(int k=x-1;k>=1;--k)
                q.push(make_pair(k,y));
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
            cout<<rz[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}