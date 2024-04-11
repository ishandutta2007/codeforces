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

const int maxn=200005;

vector<int> g[maxn];
int fat[maxn];
vector<int> son[maxn];
int now[maxn];
bool has[maxn];
int i,j,k,n;

struct hi
{
    int num;
    void push(int t)
    {
        num++;
        if(num>1)printf(" ");
        printf("%d",t);
    }
}q;

void DFS(int x,int y)
{
    fat[x]=y;
    if(now[x]<0)has[x]=true;
    for(unsigned int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(fat[v]!=0)continue;
        son[x].push_back(v);
        DFS(v,x);
        if(now[v]<0 || has[v])has[x]=true;
    }
}

void find(int x)
{
    q.push(x);
    if(x>1)now[x]=-now[x];
    if(son[x].size()==0){has[x]=false;return;}
    for(unsigned int i=0;i<son[x].size();i++)
    {
        int v=son[x][i];
        if(has[v]){find(v);now[x]=-now[x];q.push(x);}
    }
    for(unsigned int i=0;i<son[x].size();i++)
    {
        int v=son[x][i];
        if(has[v]){find(v);now[x]=-now[x];q.push(x);}
    }
    if(now[x]<0)has[x]=true;else has[x]=false;
    if(x==1 && has[x])
    {
        q.push(son[1][0]);
        q.push(x);
        q.push(son[1][0]);
    }
}

int main()
{
    scanf("%d",&n);
    memset(has,0,sizeof(has));
    for(i=1;i<=n;i++)scanf("%d",&now[i]);
    for(i=1;i<=n-1;i++)
    {
        scan2(j,k);
        g[j].push_back(k);
        g[k].push_back(j);
    }
    DFS(1,-1);
    q.num=0;
    find(1);n=0;
    return 0;
}