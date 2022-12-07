
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

const int maxn=105;
struct node
{
    int cnt,lt,lb;
    bool operator < (const struct node &p)const
    {
        if(cnt>p.cnt)return true;
        if(cnt<p.cnt)return false;
        return lt<p.lt;
    }
}s[maxn];
int n,m,k,a,ans[maxn];

int main()
{
    scanf("%d%d%d%d",&n,&k,&m,&a);
    for(int i=1;i<=n;i++)s[i].lb=i;
    for(int i=1;i<=a;i++)
    {
        int x;
        scanf("%d",&x);
        s[x].lt=i;
        s[x].cnt++;
    }
    sort(s+1,s+n+1);
    if(m==a)
    {
        for(int i=1;i<=k;i++)
            if(s[i].cnt>0)ans[s[i].lb]=1;else ans[s[i].lb]=3;
        for(int i=k+1;i<=n;i++)
            ans[s[i].lb]=3;
        for(int i=1;i<=n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
        return 0;
    }
    for(int i=k+1;i<=n;i++)
        if(s[i].cnt+m-a>s[k].cnt)ans[s[i].lb]=2;else ans[s[i].lb]=3;
    for(int i=1;i<=k;i++)
    {
        if(s[i].cnt==0){ans[s[i].lb]=2;continue;}
        int tot=m-a,pp=0;
        for(int j=i+1;j<=n;j++)
        {
            if(tot<s[i].cnt-s[j].cnt+1)break;
            pp++;tot-=(s[i].cnt-s[j].cnt+1);
        }
        if(pp+i-1>=k)ans[s[i].lb]=2;else ans[s[i].lb]=1;
    }
    for(int i=1;i<=n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}