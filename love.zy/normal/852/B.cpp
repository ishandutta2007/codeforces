#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int cnt[105],u[1000005];
int n,m,l;

struct mat
{
    int n;
    int num[105][105];

    void init0(int t)
    {
        n=t;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                num[i][j]=0;
    }

    void init1(int t)
    {
        n=t;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(i!=j)num[i][j]=0;else num[i][j]=1;
    }

    mat operator * (const struct mat p)const
    {
        struct mat ans;
        ans.init0(n);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    ans.num[i][j]=(ans.num[i][j]+1ll*num[i][k]*p.num[k][j]%mod)%mod;
        return ans;
    }       

    mat operator ^ (int t)const
    {
        struct mat ans,now;
        ans.init1(n);
        now.n=n;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                now.num[i][j]=num[i][j];
        while(t>0)
        {
            if(t&1)ans=ans*now;
            now=now*now;
            t>>=1;
        }
        return ans;
    }

};

int main()
{
    scanf("%d%d%d",&n,&l,&m);
    mat dp;
    dp.init0(m-1);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        x%=m;
        dp.num[0][x]++;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        x%=m;
        cnt[x]++;
        u[i]=x;
    }
    mat xs;
    xs.init0(m-1);
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<m;k++)
            xs.num[k][(k+i)%m]=cnt[i];
    }
    dp=dp*(xs^(l-2));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        x=(x+u[i])%m;
        ans=ans+dp.num[0][(m-x)%m];
        ans%=mod;
    }
    printf("%d\n",ans);
    return 0;
}