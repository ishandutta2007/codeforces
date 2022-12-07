
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
    int num;
    vector<int> son;
}a[1000005];
int n,m,root;
int ans[5],aa;

void DFS(int x)
{
    for(auto p : a[x].son)DFS(p);
    for(auto p : a[x].son)
    {
        a[x].num+=a[p].num;
    }
    if(a[x].num==m){ans[++aa]=x;a[x].num=0;}
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i].num=y;
        a[x].son.pb(i);
        if(x==0)root=i;
        m+=y;
    }
    if((m/3)*3!=m){printf("-1");return 0;}
    m/=3;
    DFS(root);
    if(aa>=2 && ans[1]!=root && ans[2]!=root)printf("%d %d",ans[1],ans[2]);else printf("-1");
    return 0;
}