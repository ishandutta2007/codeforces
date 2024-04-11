
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

struct node
{
    int l,r,lb;
    void read(){scanf("%d%d",&l,&r);}
}a[105];
int n,f[105];
vi le,ri;

void DFS(int x)
{
    if(a[x].l>0 && a[a[x].l].lb==0)
    {
        a[a[x].l].lb=a[x].lb;
        DFS(a[x].l);
    }
    if(a[x].r>0 && a[a[x].r].lb==0)
    {
        a[a[x].r].lb=a[x].lb;
        DFS(a[x].r);
    }
}

int find(int t)
{
    if(f[t]==t)return t;
    else return f[t]=find(f[t]);
}

int main()
{   
    scan(n);
    for(int i=1;i<=n;i++)a[i].read();
    for(int i=1;i<=n;i++)
        if(a[i].lb==0){f[i]=i;a[i].lb=i;DFS(i);}
    for(int i=1;i<=n;i++)
    {
        if(a[i].l>0 && a[i].r>0)continue;
        for(int j=1;j<=n;j++)
        {
            if(find(a[i].lb)==find(a[j].lb))continue;
            if(a[i].l+a[j].r==0)
            {
                a[i].l=j;
                a[j].r=i;
                f[find(a[j].lb)]=f[find(a[i].lb)];
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d %d\n",a[i].l,a[i].r);
    return 0;
}