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

char s[1005];
int zs,xs;
int i,n,now,t1,t2,t;
bool f;

void pp(int t)
{
    int o=100;
    while(o>0)
    {
        printf("%d",t/o);
        t%=o;
        o/=10;
    }
}

void pri(int x)
{
    if(x>=1000000)
    {
        printf("%d",x/1000000);
        x%=1000000;
        printf(".");
        pp(x/1000);
        printf(".");
        x%=1000;
        pp(x);
        return;
    }
    if(x>=1000)
    {
        printf("%d.",x/1000);
        x%=1000;
        pp(x);
        return;
    }
    printf("%d",x);
}

int find(int t)
{
    int ans=0;
    t++;
    while(s[t]>='0' && s[t]<='9'){ans++;t++;}
    return ans;
}

int ww(int t)
{
    if(t==0)return 1;
    if(t==1)return 10;
    if(t==2)return 100;
    return 1000;
}

int main()
{
    gets(s);
    n=strlen(s);
    s[n]='a';
    for(i=0;i<=n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            if(now<=2 && f)t2=t2*ww(now)+t;else t1=t1*1000+t;
            xs+=t2;zs+=t1;
            now=t1=t2=t=0;
            f=false;
            continue;
        }
        if(s[i]=='.')
        {
            t1=t1*ww(now)+t;
            t=now=0;
            f=true;
            continue;
        }
        t=t*10+s[i]-48;
        now++;
    }
    zs=zs+xs/100;
    xs%=100;
    pri(zs);
    if(xs>=10)printf(".%d",xs);
    if(xs>0 && xs<10)printf(".0%d",xs);
    return 0;
}