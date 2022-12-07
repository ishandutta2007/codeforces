
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
#define scan(x) scanf("%d", &x)
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

int n,m,q;
LL a[maxn],b[maxn],sum,tot=0;
vector<LL> g;

int main()
{
    g.pb(-1e18);g.pb(1e18);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(i&1)sum+=a[i];else sum-=a[i];
    }
    for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)
        if(i&1)tot+=b[i];else tot-=b[i];
    g.pb(tot);
    for(int i=n+1;i<=m;i++)
    {
        tot-=b[i-n];
        tot*=-1;
        if(n&1)tot+=b[i];else tot-=b[i];
        g.pb(tot);
    }
    sort(g.begin(),g.end());
    int t=lower_bound(g.begin(),g.end(),sum)-g.begin();
    printf("%lld\n",min(abs(sum-g[t]),abs(sum-g[t-1])));
    while(q--)
    {
        int l,r;LL x;
        scanf("%d%d%lld",&l,&r,&x);
        if((r-l+1)&1)
        {
            if(l&1)sum+=x;
            else sum-=x;
        }
        t=lower_bound(g.begin(),g.end(),sum)-g.begin();
        printf("%lld\n",min(abs(sum-g[t]),abs(sum-g[t-1])));
    }
    return 0;
}