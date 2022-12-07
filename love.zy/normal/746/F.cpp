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

int t[maxn],a[maxn];

multiset<int> ha,fu;
multiset<int>::iterator it;
int i,j,k,l,m,n,r,tot,ans,sum;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&t[i]);
    a[0]=0;
    for(i=1;i<=n;i++)a[i]+=a[i-1];
    tot=ans=sum=0;
    for(l=1,j=0;l<=n;l++)
    {
        while(tot-sum<=k && r<=n)
        {
            ans=max(ans,a[r]-a[l-1]);
            r++;
            if(r>n)break;
            ha.insert(t[r]);
            tot+=t[r];sum+=t[r]/2;
            if(ha.size()>m)
            {
                it=ha.begin();
                sum-=(*it)/2;
                fu.insert((*it));
                ha.erase(it);
            }
        }
        it=fu.find(t[l]);
        if(it!=fu.end())
        {
            tot-=(*it);
            fu.erase(it);
        }else
        {
            it=ha.find(t[l]);
            tot-=(*it);
            sum-=(*it)/2;
            ha.erase(it);
            it=fu.end();
            if(it!=fu.begin())
            {
                it--;
                ha.insert((*it));
                sum+=(*it)/2;
                fu.erase(it);
            }
        }
    }
    printf("%d",ans);
    return 0;
}