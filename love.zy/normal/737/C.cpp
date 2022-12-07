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
int a[maxn],sum[maxn];
int i,k,l,m,n;
unsigned int j=0;
int ans=0;
vector<int> p;
bool b[maxn];

int main()
{
    scan2(n,m);
    for(i=1;i<=n;i++)scan(a[i]),sum[a[i]]++;
    if(a[m]==0)
    {
        for(i=1;i<=n;i++)if(i!=m && a[i]==0)ans++,p.push_back(i);
    }else
    {
        ans++;sum[a[m]]--;a[m]=0;
        for(i=1;i<=n;i++)if(i!=m && a[i]==0)ans++,p.push_back(i);
    }
    if(n==1){printf("%d",ans);return 0;}
    int k=n-1;
    while(k>1 && sum[k]==0)k--;
    for(i=1;i<=k;i++)
    {
        if(sum[i]>0)continue;
        if(j<p.size()){sum[i]=1;a[p[j++]]=i;b[i]=true;}
    }
    i=0;
    while(i<k)
    {
        i++;
        if(i==k)break;
        if(sum[i]>0)continue;
        sum[k]--;sum[i]=1;ans++;
        while(k>1 && sum[k]==0)k--;
    }
    printf("%d",ans);
    return 0;
}