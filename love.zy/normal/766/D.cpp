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
 
map<string,int> mp;
map<int,int> en[100005];
int fat[100005],dis[100005];
int i,m,n,q;

int find(int now)
{
    if(fat[now]==now)return now;
    else
    {
        int t=fat[now];
        fat[now]=find(t);
        dis[now]+=dis[t];
        return fat[now];
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mp[s]=i;
    }
    for(i=1;i<=n;i++)fat[i]=i,dis[i]=0;
    while(m--)
    {
        string s1,s2;
        int x,y;
        cin>>i>>s1>>s2;
        x=mp[s1];y=mp[s2];
        int xx=find(x),yy=find(y);
        int f=5;
        if(xx==yy && (dis[x]+dis[y])%2==0)f=0;
        if(xx==yy && (dis[x]+dis[y])%2==1)f=1;
        if(f==5)
        {
            printf("YES\n");
            fat[xx]=fat[yy];
            if((dis[x]+dis[y])%2==1)i=3-i;
            if(i==1)dis[xx]=2;else dis[xx]=1;
            continue;
        }
        if(i-1!=f)printf("NO\n");else printf("YES\n");
    }
    while(q--)
    {
        string s1,s2;
        int x,y;
        cin>>s1>>s2;
        x=mp[s1];y=mp[s2];
        int xx=find(x),yy=find(y);
        if(xx==yy && (dis[x]+dis[y])%2==0){printf("1\n");continue;}
        if(xx==yy && (dis[x]+dis[y])%2==1){printf("2\n");continue;}
        printf("3\n");
    }
    return 0;
}