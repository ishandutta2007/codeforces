
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
  
struct node
{
    LL a,b,v;
    bool operator <(const struct node p)const
    {return b<p.b || (b==p.b && a<p.a);}
}c[100005];
stack<node> s;
int n;
LL ans,tot;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&c[i].a,&c[i].b,&c[i].v);
    sort(c+1,c+n+1);
    while(!s.empty())s.pop();
    struct node temp = {0,(LL)1e9+7,0};
    s.push(temp);
    int i=n;
    while(i>=1)
    {
        while(s.top().a>=c[i].b)
        {
            struct node p=s.top();
            s.pop();
            tot-=p.v;
        }
        s.push(c[i]);
        tot+=c[i].v;
        ans=max(ans,tot);
        i--;
    }
    printf("%lld",ans);
    return 0;
}