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

map<int,int> mp;
vector<int> q;
int i,j,k,l,m,n;
int a[2005];

int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)mp[i]=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        a[i]=k;
        int t=mp.count(k);
        if(t>0)mp[k]++;else mp[k]=2;
    }
    l=0;q.clear();
    int ans=n/m+1;
    for(i=1;i<=m;i++)
        if(mp[i]<ans)q.push_back(i);
    j=0;
    while(j<q.size())
    {
        for(i=1;i<=n;i++)
        {
            if(a[i]>m)
            {
                l++;
                mp[a[i]]--;
                a[i]=q[j];
                mp[q[j]]++;
                if(mp[q[j]]>=ans)j++;
                if(j==q.size())break;
            }
        }
        if(j==q.size())break;
        for(i=1;i<=n;i++)
        {
            if(mp[a[i]]>ans)
            {
                l++;
                mp[a[i]]--;
                a[i]=q[j];
                mp[q[j]]++;
                if(mp[q[j]]>=ans)j++;
                if(j==q.size())break;
            }
        }
    }
    printf("%d %d\n",ans-1,l);
    for(i=1;i<=n;i++)
    {   
        if(i>1)printf(" ");
        printf("%d",a[i]);
    }
    return 0;
}