
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

LL GCD(LL x,LL y)
{
    if(x==0)return y;
    if(y==0)return x;
    return GCD(y,x%y);
}

LL a[100005];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    LL t=GCD(a[1],a[2]);
    for(int i=3;i<=n;i++)t=GCD(t,a[i]);
    if(t>1)
    {
        printf("YES\n");
        printf("0\n");
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n-1;i++)
    {
        if((a[i]&1)==0)continue;
        if((a[i]&1) && (a[i+1]&1))
        {
            ans++;
            a[i]=2;a[i+1]=2;
            continue;
        }
        ans+=2;
        a[i]=2;
    }
    if(a[n]&1)ans+=2;
    printf("YES\n");
    printf("%d\n",ans);
    return 0;
}