
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
#define scan2(x, y) scanf("%d%d", &x, &y)
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

const int maxn=10000005;
int a[maxn],b[maxn];
int n,m,ma,mb,k;
vector<int> va;
vector<int> num[maxn];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;ma=max(ma,x);
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        b[x]++;mb=max(mb,x);
        num[x].pb(i);
    }
    int sum=0,tot=0,ans=0;
    for(int i=0;i<=ma;i++)
    {
        sum+=k;tot+=a[i];
        if(sum<tot){printf("-1");return 0;}
        if(sum>n)break;
    }
    int i=0;
    sum=tot=0;
    mb=max(ma,mb);
    while(i<=mb)
    {
        sum+=k;
        if(sum>n+m)sum=n+m;
        tot+=a[i];
        int j=0;
        while(tot<sum && b[i]>0)
        {
            tot++;ans++;
            va.pb(num[i][j]);
            b[i]--;j++;
        }
        i++;
    }
    sum=tot=0;
    printf("%d\n",ans);
    for(unsigned int i=0;i<va.size();i++)
    {
        if(i>0)printf(" ");
        printf("%d",va[i]);
    }
    return 0;
}