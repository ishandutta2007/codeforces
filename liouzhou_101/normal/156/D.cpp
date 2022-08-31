#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=100010;

int n,m,num;
long long k;
int F[MaxN],p[MaxN],v[MaxN];

inline int father(const int &x)
{
    return (F[x]==x)?x:F[x]=father(F[x]);
}

inline long long power(long long x,int n)
{
    if (!n) return 1;
    long long tmp=power(x,n>>1);
    tmp*=tmp;
    tmp%=k;
    if (n&1)
    {
        tmp*=x;
        tmp%=k;
    }
    return tmp;
}

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        F[i]=i;
    for (int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        F[father(x)]=father(y);
    }
    for (int i=1;i<=n;++i)
        ++p[father(i)];
    for (int i=1;i<=n;++i)
        if (p[i]) v[++num]=p[i];
    if (num==1)
        cout<<1%k<<endl;
    else
    {
        long long sum=0,ans=1;
        for (int i=1;i<=num;++i)
        {
            sum+=v[i];
            while (sum>=k) sum-=k;
            ans*=v[i];
            ans%=k;
        }
        ans*=power(sum,num-2);
        cout<<ans%k<<endl;
    }
    return 0;
}