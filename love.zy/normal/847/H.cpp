
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%lld", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int maxn=100005;
LL pre[maxn],suf[maxn],a[maxn],p[maxn],s[maxn];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scan(a[i]);
    LL ma=0;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+max(ma+1-a[i],0ll),ma=max(ma+1,a[i]),p[i]=ma;
    ma=0;
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+max(ma+1-a[i],0ll),ma=max(ma+1,a[i]),s[i]=ma;
    LL ans=1e18;
    for(int i=0;i<=n;i++)
        ans=min(ans,pre[i]+suf[i+1]+(p[i]==s[i+1]));
    printf("%lld\n",ans);
    return 0;
}