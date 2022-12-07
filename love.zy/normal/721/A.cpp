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
  
char s[105];
queue<int> q;
int i,n,j,m;

int main()
{
    scanf("%d\n",&n);
    gets(s+1);m=0;
    i=1;
    while(i<=n)
    {
        while(s[i]!='B')i++;
        if(i>n)break;
        j=0;
        while(s[i]=='B'){j++;i++;}
        if(j>0)
        {
            q.push(j);
            m++;
        }
    }
    printf("%d\n",m);
    j=0;
    while(!q.empty())
    {
        j++;
        if(j>1)printf(" ");
        printf("%d",q.front());
        q.pop();
    }
    return 0;
}