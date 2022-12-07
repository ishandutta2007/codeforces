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

char s1[1005];
char s2[1005];
bool fk[30];
int l1,l2;
int i,j,k,l,m,n;
int a[30];
vector<int> g;

int main()
{
    gets(s1);gets(s2);
    l1=strlen(s1);l2=strlen(s2);
    g.clear();
    memset(fk,0,sizeof(fk));
    for(i=0;i<l1;i++)
    {
        if(s1[i]==s2[i])
        {
            if(a[s1[i]-96]!=0){printf("-1");return 0;}
            fk[s1[i]-96]=true;
            continue;
        }
        if(fk[s1[i]-96] || fk[s2[i]-96])
        {printf("-1");return 0;}
        if(a[s1[i]-96]!=0 && a[s1[i]-96]!=s2[i]-96)
        {printf("-1");return 0;}
        if(a[s2[i]-96]!=0 && a[s2[i]-96]!=s1[i]-96)
        {printf("-1");return 0;}
        if(a[s1[i]-96]!=0)continue;
        a[s1[i]-96]=s2[i]-96;
        a[s2[i]-96]=s1[i]-96;
        g.push_back(s1[i]-96);
    }
    printf("%d\n",g.size());
    for(i=0;i<g.size();i++)printf("%c %c\n",g[i]+96,a[g[i]]+96);
    return 0;
}