# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

int prime[10000],cnt=0;
namespace prime_make{
    const int maxn=100010;
    bool p[maxn];
    void main()
    {
        int i=2,j;
        memset(p,0,sizeof(p));
        while(i*i<=maxn)
        {
            for(j=i*i;j<=maxn;j+=i)
                p[j]=true;
            ++i;
            while(p[i]&&i<=maxn)i++;
        }
        for(int i=2;i<=maxn;i++)
            if(!p[i])prime[cnt++]=i;
    }
}

int find(int x)
{
    if(x<=2)return 2-x;
    int mid,L=0,R=cnt;
    while(R-L>1)
        (prime[mid=(L+R)>>1]<x)?L=mid:R=mid;
    return prime[R]-x;
}

int a[501][501];
int r[501],c[501];
int n,m;

int main()
{
    prime_make::main();
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]=find(a[i][j]);
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            r[i]+=a[i][j],c[j]+=a[i][j];
    int ans=r[0];
    for(int i=0;i<n;i++)ans=min(ans,r[i]);
    for(int j=0;j<m;j++)ans=min(ans,c[j]);
    cout << ans << endl;
}