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

const int maxn=1000005;
int a[maxn],n,m;
vi g[maxn];
vector<LL> sum[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)g[i].pb(0),sum[i].pb(0);
    for(int i=n;i>=2;i--)
    {
        int f=i>>1;
        for(int p : g[i])
            g[f].pb(p+a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end());
        for(unsigned int j=1;j<g[i].size();j++)
        {
            LL temp=sum[i][j-1]+1ll*g[i][j];
            sum[i].pb(temp);
        }
        g[i].pb(1e9);sum[i].pb(1e18);
    }
    while(m--)
    {
        int x,y,yy,tot=0;
        scanf("%d%d",&x,&y);yy=y;
        LL ans=0,cnt=0;
        int lb=lower_bound(g[x].begin(),g[x].end(),y)-g[x].begin();
        if(g[x][lb]==y)lb++;
        cnt+=lb;
        ans+=sum[x][lb-1];
        while(x>1)
        {
            y-=a[x];tot+=a[x];
            if(y<0)break;
            int f=(x&1)?x-1:x+1;
            cnt++;ans+=tot;
            if(f<=n && y>=a[f])
            {
                int s=lower_bound(g[f].begin(),g[f].end(),y-a[f])-g[f].begin();
                if(g[f][s]==y-a[f])s++;
                cnt+=s;
                ans+=1ll*s*(tot+a[f])+sum[f][s-1];
            }
            x>>=1;
        }
        printf("%lld\n",1ll*yy*cnt-ans);
    }
    return 0;
}