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
LL x;
LL a[maxn];
LL i,j,k,l,m,n;
LL o,w,e;

struct number
{
    int pos;
    LL num,xs;
    number(int pos=0,LL num=0,LL xs=0):pos(pos),num(num),xs(xs){}
    bool operator < (struct number p)const {return num>p.num;}
};

priority_queue< number > q;

LL abss(LL r)
{
    return r<0?-r:r;
}

void prin()
{
    while(!q.empty())
    {
        number temp=q.top();q.pop();
        a[temp.pos]=temp.num*temp.xs;
    }
    for(int i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%lld",a[i]);
    }
}

int main()
{
    scanf("%lld %lld %lld",&n,&m,&x);
    while(!q.empty())q.pop();
    e=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        if(k<0)e++;
        LL u;
        if(k<0)u=-1;
        if(k>=0)u=1;
        q.push(number(i,abss(k),u));
    }
    
    if(e%2==1)
    {
        while(m>0)
        {
            m--;
            number temp=q.top();q.pop();
            temp.num+=x;q.push(temp);
        }
        prin();
        return 0;
    }
    
    number t=q.top();

    if(t.num-x*m>=0)
    {
        q.pop();
        t.num-=x*m;
        q.push(t);
        prin();
        return 0;
    }

    if(t.num-x*m<0)
    {
        q.pop();
        k=t.num/x;
        k++;
        t.num-=k*x;
        m-=k;
        t.num=abss(t.num);
        t.xs=-t.xs;
        q.push(t);
        while(m>0)
        {
            m--;
            number temp=q.top();q.pop();
            temp.num+=x;q.push(temp);
        }
        prin();
    }
    return 0;
}