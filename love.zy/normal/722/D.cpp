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
map<int,int>::iterator it;
priority_queue<int> q;
int i,m,n,p;

int pd(int t)
{
    while(t>0)
    {
        if(mp.count(t)==0)return t;
        t/=2;
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    mp.clear();p=0;
    while(!q.empty())q.pop();
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        q.push(m);
        mp[m]=++p;
    }
    while(1)
    {
        m=q.top();
        i=pd(m);
        if(i>0)
        {
            q.pop();
            m=i;
            mp[m]=++p;
            q.push(m);
        }else break;
    }
    m=0;
    while(!q.empty())
    {
        m++;
        if(m>1)printf(" ");
        printf("%d",q.top());
        q.pop();
    }
    return 0;
}