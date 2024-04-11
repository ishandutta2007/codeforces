
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

struct node
{
    int l,r;
    bool operator < (const struct node p)const
    {return l<p.l || (l==p.l && r<p.r);}
    void read(){scanf("%d%d",&l,&r);}
}a[200005];
int x=-1,y=-1,n;

bool solve()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i].l>x){x=a[i].r;continue;}
        if(a[i].l>y){y=a[i].r;continue;}
        return false;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i].read();
    sort(a+1,a+n+1);
    if(solve())printf("YES\n");else printf("NO\n");
    return 0;
}