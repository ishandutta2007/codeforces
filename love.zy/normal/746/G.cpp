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
  
int n,m,k;
int i,j,l;
int p,q,ma;
int a[200005];
int ans[200005][2];
int f;
vector<int> g,gg;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
    }
    if(k>n-m || k<ma)
    {
        printf("-1");
        return 0;
    }
    g.clear();
    for(i=2;i<=a[1]+1;i++)
    {
        ans[++f][0]=1;
        ans[f][1]=i;
        g.push_back(i);
    }
    l=n-m;j=a[1]+1;
    for(i=2;i<=m;i++)
    {
        int p=0;gg.clear();q=1;
        while(p<a[i])
        {
            p++;j++;
            gg.push_back(j);
            if(p==1)
            {
                ans[++f][0]=g[0];
                ans[f][1]=j;
                continue;
            }
            if(l>k && q<g.size())
            {
                ans[++f][0]=g[q++];
                ans[f][1]=j;
                l--;
            }else 
            {
                ans[++f][0]=g[0];
                ans[f][1]=j;
            }
        }
        g=gg;
    }
    if(l>k){printf("-1");return 0;}
    printf("%d\n",n);
    for(i=1;i<=f;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}