#include<cstdio>
#include<algorithm>
#define f(i,n) for(i=1;i<=n;i++)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
int i,j,a[1005][1005],ans=0,n,q,d,x;
int main(void)
{
    scanf("%d",&n);
    f(i,n) f(j,n) scanf("%d",&a[i][j]);
    f(i,n) ans=(ans+a[i][i])%2;
    scanf("%d",&q);
    f(i,q)
    {
        scanf("%d",&d);
        if(d==3) printf("%d",ans);
        else{
            scanf("%d",&x);ans=(ans+1)%2;
        }
    }
}