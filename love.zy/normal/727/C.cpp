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

const int maxn=5005;

int num[maxn],ans[maxn];
int i,n;

int QA(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int t;
    scan(t);
    return t;
}

int main()
{
    scanf("%d",&n);
    for(i=2;i<=n;i++)num[i]=QA(1,i);
    num[1]=QA(2,3);
    int tot=num[1]+num[2]+num[3];
    tot/=2;
    ans[1]=tot-num[1];
    ans[3]=tot-num[2];
    ans[2]=tot-num[3];
    for(i=4;i<=n;i++)ans[i]=num[i]-ans[1];
    printf("!");
    for(i=1;i<=n;i++)printf(" %d",ans[i]);
    return 0;
}