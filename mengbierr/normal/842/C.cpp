#include <cstdio>  
#include <vector>  
#include <queue>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
#define mst(a,b) memset((a),(b),sizeof(a))  
  
typedef long long ll;  
const int maxn = 200005;  
const ll mod = 1e9+7;  
const int INF = 0x3f3f3f3f;  
const double eps = 1e-9;  
  
int gcd(int a,int b)  
{  
    return b?gcd(b,a%b):a;  
}  
  
int n,cnt;  
int a[maxn],dp[maxn];  
int head[maxn];  
vector<int>vec[maxn];  
  
struct node  
{  
    int v,next;  
}e[maxn*2];  
  
void add(int u,int v)  
{  
    e[cnt].v=v;  
    e[cnt].next=head[u];  
    head[u]=cnt++;  
}  
  
void dfs(int u,int pre)  
{  
    for(int i=head[u];~i;i=e[i].next)  
    {  
        int v=e[i].v;  
        if(v==pre) continue;  
        dp[v]=gcd(dp[u],a[v]);  
        vec[v].push_back(dp[u]);   //  
        for(int i=0;i<vec[u].size();i++)  
        {  
            vec[v].push_back(gcd(vec[u][i],a[v]));  
        }  
        sort(vec[v].begin(),vec[v].end());                     //  
        vec[v].erase(unique(vec[v].begin(),vec[v].end()),vec[v].end());  
        dfs(v,u);  
    }  
}  
  
int main()  
{  
    mst(head,-1);  
    cnt=0;  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&a[i]);  
    }  
    int x,y;  
    for(int i=0;i<n-1;i++)  
    {  
        scanf("%d%d",&x,&y);  
        add(x,y);  
        add(y,x);  
    }  
    dp[1]=a[1];  
    vec[1].push_back(0);  
    dfs(1,-1);  
    for(int i=1;i<=n;i++)  
    {  
        dp[i]=max(dp[i],vec[i].back());  //  
    }  
    for(int i=1;i<n;i++)  
    {  
        printf("%d ",dp[i]);  
    }  
    printf("%d\n",dp[n]);  
}