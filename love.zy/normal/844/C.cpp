
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

const int maxn=100005;
int ls[maxn],lsh[maxn],cnt,a[maxn],n;
typedef vector<int> vi;
vector< vi > ans;
bool vis[maxn];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),lsh[i]=a[i];
    sort(lsh+1,lsh+n+1);
    ls[cnt=1]=lsh[1];
    for(int i=2;i<=n;i++)if(lsh[i]!=lsh[i-1])ls[++cnt]=lsh[i];
    for(int i=1;i<=n;i++)a[i]=lower_bound(ls+1,ls+cnt+1,a[i])-ls;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        vi now;
        now.clear();
        int t=i;
        while(!vis[t])
        {
            vis[t]=true;
            now.pb(t);
            t=a[t];
        }
        ans.pb(now);
    }
    printf("%d\n",ans.size());
    for(vi p : ans)
    {
        printf("%d",p.size());
        for(int q : p)printf(" %d",q);
        printf("\n");
    }
    return 0;
}