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
  
char s[200005];
int i,j,k,l,m,n,p,q;
int ans;
queue<int> qq;
int main()
{
    scanf("%d %d %d %d\n",&n,&p,&q,&m);
    gets(s+1);k=0;
    for(i=1;i<=n;i++)
    {
        if(s[i]=='1')
        {
            l+=(i-k-1)/q;
            k=i;
        }
    }
    l+=(n+1-k-1)/q;
    if(l<p){printf("0");return 0;}
    k=0;
    for(i=1;i<=n;i++)
    {
        if(s[i]=='0')
        {
            k++;
            if(k>=q)
            {
                k=0;l--;ans++;
                qq.push(i);
                if(l<p)break;
            }
        }else k=0;
    }
    printf("%d\n",ans);
    ans=0;
    while(!qq.empty())
    {
        ans++;
        if(ans>1)printf(" ");
        printf("%d",qq.front());
        qq.pop();
    } 
    return 0;
}