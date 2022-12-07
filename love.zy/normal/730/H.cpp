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

string s[105];
int a[105];
bool b[105];
bool c[105];
int i,j,k,l,m,n;

int main()
{
    memset(c,0,sizeof(c));
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>s[i];
    for(i=1;i<=m;i++)
    {
        cin>>a[i];
        c[a[i]]=true;
    }
    sort(a+1,a+m+1);
    for(i=0;i<s[a[1]].length();i++)b[i]=false;
    for(k=2;k<=m;k++)
    {
        if(s[a[k]].length()!=s[a[1]].length())
        {
            printf("No");
            return 0;
        }
        for(j=0;j<s[a[1]].length();j++)
        {
            if(b[j])continue;
            if(s[a[1]][j]!=s[a[k]][j])b[j]=true;
        }
    }
    for(k=1;k<=n;k++)
    {
        if(c[k])continue;
        if(s[k].length()!=s[a[1]].length())continue;
        bool f=true;
        for(j=0;j<s[k].length();j++)
            if(!b[j] && s[k][j]!=s[a[1]][j])
            {
                f=false;
                break;
            }
        if(f){printf("No");return 0;}
    }
    printf("Yes\n");
    for(j=0;j<s[a[1]].length();j++)
        if(!b[j])printf("%c",s[a[1]][j]);else printf("?");
    return 0;
}