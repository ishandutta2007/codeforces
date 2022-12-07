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
  
bool f;
int s[100];

void dfs(int x,int y)
{
    if(y<x)return;
    if(y==x)
    {
        f=true;
        s[++s[0]]=y;
        return;
    }
    if(y%2==0)dfs(x,y/2);
    if(f)
    {
        s[++s[0]]=y;
        return;
    }
    if(y>10 && y%10==1)dfs(x,y/10);
    if(f)
    {
        s[++s[0]]=y;
        return;
    }
}

int main()
{   
    int a,b;
    f=false;
    memset(s,0,sizeof(s));
    scan2(a,b);
    dfs(a,b);
    if(!f){printf("NO");return 0;}
    printf("YES\n");
    printf("%d\n",s[0]);
    for(int i=1;i<=s[0];i++)
    {
        if(i>1)printf(" ");
        printf("%d",s[i]);
    }
    return 0;
}