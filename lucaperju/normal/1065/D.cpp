#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

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
pair<int,int> dp[3][11][11][11][11];
int xs[101],ys[101];
int v[11][11];
int dx[]={-2,-2,-1,1,2,2,1,-1};
int dy[]={-1,1,2,2,1,-1,-2,-2};
struct ura
{
    int fel,xc,yc,xd,yd;
};
queue<ura>q;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,j=0,tt,p,n;
    t=1;
    //cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            {
                cin>>v[i][j];
                xs[v[i][j]]=i;
                ys[v[i][j]]=j;
            }
        for(i=0;i<=2;++i)
            for(int a=1;a<=n;++a)
                for(int b=1;b<=n;++b)
                    for(int c=1;c<=n;++c)
                        for(int d=1;d<=n;++d)
                            dp[i][a][b][c][d]=make_pair(1000000,1000000);
        for(i=0;i<=2;++i)
        {
            dp[i][xs[1]][ys[1]][xs[2]][ys[2]]=make_pair(0,0);
            q.push({i,xs[1],ys[1],xs[2],ys[2]});
        }
        pair<int,int>rz=make_pair(1000000,1000000);
        while(!q.empty())
        {
            ura a=q.front();
            q.pop();
            pair<int,int> dstc=dp[a.fel][a.xc][a.yc][a.xd][a.yd];
            ura av=a;
            if(a.xc==a.xd && a.yc==a.yd)
            {
                if(v[a.xc][a.yc]==n*n)
                {
                    rz=min(rz,dstc);
                    continue;
                }
                a.xd=xs[v[a.xc][a.yc]+1];
                a.yd=ys[v[a.xc][a.yc]+1];
            }
            dp[a.fel][a.xc][a.yc][a.xd][a.yd]=dp[av.fel][av.xc][av.yc][av.xd][av.yd];
            if(a.fel==0) /// bishop
            {
                i=a.xc;
                j=a.yc;
                if(dp[1][i][j][a.xd][a.yd]>make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1))
                {
                    dp[1][i][j][a.xd][a.yd]=make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1);
                    q.push({1,i,j,a.xd,a.yd});
                }
                if(dp[2][i][j][a.xd][a.yd]>make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1))
                {
                    dp[2][i][j][a.xd][a.yd]=make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1);
                    q.push({2,i,j,a.xd,a.yd});
                }
                for(i=1;i<=n;++i)
                    for(j=1;j<=n;++j)
                    {
                        if(i+j==a.xc+a.yc || i-j==a.xc-a.yc)
                        {
                            if(dp[a.fel][i][j][a.xd][a.yd]>make_pair(1+dp[a.fel][a.xc][a.yc][a.xd][a.yd].first,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second))
                            {
                                dp[a.fel][i][j][a.xd][a.yd]=make_pair(1+dp[a.fel][a.xc][a.yc][a.xd][a.yd].first,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second);
                                q.push({a.fel,i,j,a.xd,a.yd});
                            }
                        }
                    }
            }
            else if(a.fel==1) /// rook
            {
                i=a.xc;
                j=a.yc;
                if(dp[0][i][j][a.xd][a.yd]>make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1))
                {
                    dp[0][i][j][a.xd][a.yd]=make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1);
                    q.push({0,i,j,a.xd,a.yd});
                }
                if(dp[2][i][j][a.xd][a.yd]>make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1))
                {
                    dp[2][i][j][a.xd][a.yd]=make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1);
                    q.push({2,i,j,a.xd,a.yd});
                }
                for(i=1;i<=n;++i)
                    for(j=1;j<=n;++j)
                    {
                        if(i==a.xc|| j==a.yc)
                        {
                            if(dp[a.fel][i][j][a.xd][a.yd]>make_pair(1+dp[a.fel][a.xc][a.yc][a.xd][a.yd].first,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second))
                            {
                                dp[a.fel][i][j][a.xd][a.yd]=make_pair(1+dp[a.fel][a.xc][a.yc][a.xd][a.yd].first,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second);
                                q.push({a.fel,i,j,a.xd,a.yd});
                            }
                        }
                    }
            }
            else
            {
                i=a.xc;
                j=a.yc;
                if(dp[0][i][j][a.xd][a.yd]>make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1))
                {
                    dp[0][i][j][a.xd][a.yd]=make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1);
                    q.push({0,i,j,a.xd,a.yd});
                }
                if(dp[1][i][j][a.xd][a.yd]>make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1))
                {
                    dp[1][i][j][a.xd][a.yd]=make_pair(dp[a.fel][a.xc][a.yc][a.xd][a.yd].first+1,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second+1);
                    q.push({1,i,j,a.xd,a.yd});
                }
                for(i=1;i<=n;++i)
                    for(j=1;j<=n;++j)
                    {
                        int idk=abs(i-a.xc);
                        int idk1=abs(j-a.yc);
                        if(idk1*idk==2 && idk1+idk==3)
                        {
                            if(dp[a.fel][i][j][a.xd][a.yd]>make_pair(1+dp[a.fel][a.xc][a.yc][a.xd][a.yd].first,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second))
                            {
                                dp[a.fel][i][j][a.xd][a.yd]=make_pair(1+dp[a.fel][a.xc][a.yc][a.xd][a.yd].first,dp[a.fel][a.xc][a.yc][a.xd][a.yd].second);
                                q.push({a.fel,i,j,a.xd,a.yd});
                            }
                        }
                    }
            }
        }
        cout<<rz.first<<' '<<rz.second;
    }
    return 0;
}