#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

const int maxn=100005;

struct node
{
    char c;
    int pos;
    node(char c='.',int pos=0):c(c),pos(pos){}
    bool operator < (const struct node p)
    {
        if(c<p.c)return true;
        if(c>p.c)return false;
        return pos>p.pos;
    }
};

struct tree
{
    int ll,rr,ls,rs;
    struct node num;
}a[3*maxn];

char s[maxn];
char ans[maxn];
int tot[27];
int tt[27];
int i,j,k,l,m,n,t;

struct node mini(node p,node q)
{
    return p<q?p:q;
}

void mt(int x,int y)
{
    if(x==y)
    {
        a[k].ll=a[k].rr=x;
        a[k].ls=a[k].rs=0;
        a[k].num.c=s[x];
        a[k].num.pos=x;
        return;
    }
    a[k].ll=x;a[k].rr=y;
    int mid=(x+y)>>1;
    int t=k;
    k++;a[t].ls=k;mt(x,mid);
    k++;a[t].rs=k;mt(mid+1,y);
    a[t].num=mini(a[a[t].ls].num,a[a[t].rs].num);
}

struct node find(int x,int y,int now)
{
    if(a[now].ll==x && a[now].rr==y)return a[now].num;
    int mid=(a[now].ll+a[now].rr)>>1;
    if(y<=mid)return find(x,y,a[now].ls);
    if(x>mid)return find(x,y,a[now].rs);
    return mini(find(x,mid,a[now].ls),find(mid+1,y,a[now].rs));
}

int main()
{
    scanf("%d\n",&m);
    gets(s+1);
    n=strlen(s+1);
    for(i=1;i<=n;i++)tot[s[i]-96]++;
    k=1;mt(1,n);t=0;i=1;
    while(i<=n-m+1)
    {
        struct node tmp=find(i,i+m-1,1);
        ans[++t]=tmp.c;
        i=tmp.pos+1;
    }
    for(i=1;i<=t;i++)tt[ans[i]-96]++;
    for(i=1;i<=26;i++)
    {
        if(t==tt[i])
        {
            for(j=1;j<=tt[i];j++)printf("%c",96+i);
            break;
        }
        t-=tt[i];
        for(j=1;j<=tot[i];j++)printf("%c",96+i);
    }
    return 0;
}