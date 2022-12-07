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

struct point
{
    LL x,y;
    bool operator == (const struct point p)const
    {return x==p.x && y==p.y;}
}king,now,pos[20],ch[500005];

char c[500005];

int i,j,k,l,m,n;

/*
 * 123
 * 4k5
 * 678
 */

bool pd(point t)
{
    if(t.x==king.x || t.y==king.y)return true;
    if(t.x+t.y==king.x+king.y)return true;
    if(t.x-t.y==king.x-king.y)return true;
    return false;
}

void upd(point t)
{
    if(t.x==king.x)
    {
        if(t.y>king.y)
        {
            if(pos[2].y==king.y || pos[2].y>t.y)pos[2].y=t.y;
            return;
        }
        if(t.y<king.y)
        {
            if(pos[7].y==king.y || pos[7].y<t.y)pos[7].y=t.y;
            return;
        }
    }
    if(t.x>king.x)
    {
        if(t.y==king.y)
        {
            if(pos[5].x==king.x || pos[5].x>t.x)pos[5].x=t.x;
            return;
        }
        if(t.y<king.y)
        {
            if(pos[8]==king || t.y>pos[8].y)pos[8]=t;
            return;
        }
        if(t.y>king.y)
        {
            if(pos[3]==king || t.y<pos[3].y)pos[3]=t;
            return;
        }
    }
    if(t.x<king.x)
    {
        if(t.y==king.y)
        {
            if(pos[4].x==king.x || pos[4].x<t.x)pos[4].x=t.x;
            return;
        }
        if(t.y<king.y)
        {
            if(pos[6]==king || t.y>pos[6].y)pos[6]=t;
            return;
        }
        if(t.y>king.y)
        {
            if(pos[1]==king || t.y<pos[1].y)pos[1]=t;
            return;
        }
    }
}

int main()
{
    scanf("%d %lld %lld\n",&n,&king.x,&king.y);
    for(i=1;i<=8;i++)pos[i]=king;
    for(i=1;i<=n;i++)
    {
        scanf("%c %lld %lld\n",&c[i],&now.x,&now.y);
        if(pd(now))upd(now);
        ch[i]=now;
    }
    for(i=1;i<=n;i++)
    {
        if(!pd(ch[i]))continue;
        if(c[i]=='B')
        {
            if(ch[i]==pos[1] || ch[i]==pos[3] || ch[i]==pos[6] || ch[i]==pos[8]){printf("YES");return 0;}
            continue;
        }
        if(c[i]=='R')
        {
            if(ch[i]==pos[2] || ch[i]==pos[4] || ch[i]==pos[5] || ch[i]==pos[7]){printf("YES");return 0;}
            continue;
        }
        if(c[i]=='Q')
        {
            if(ch[i]==pos[1] || ch[i]==pos[3] || ch[i]==pos[6] || ch[i]==pos[8]){printf("YES");return 0;}
            if(ch[i]==pos[2] || ch[i]==pos[4] || ch[i]==pos[5] || ch[i]==pos[7]){printf("YES");return 0;}
            continue;
        }
    }
    printf("NO");
    return 0;
}