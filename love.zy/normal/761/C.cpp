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
 
int a[55][2][2][2];//digit,letters,character
char s[55][55];
int i,j,k,l,m,n;

int cal(int p,int q)
{
    if(p>q)swap(p,q);
    return min(q-p,p+m-q);
}

int main()
{
    scanf("%d%d\n",&n,&m);
    for(i=1;i<=n;i++)gets(s[i]+1);
    memset(a,0x3f3f3f3f,sizeof(a));
    a[0][0][0][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i][j]>='0' && s[i][j]<='9')
            {
                    for(int x=0;x<=1;x++)
                        for(int y=0;y<=1;y++)
                        {
                            a[i][1][x][y]=min(a[i][1][x][y],a[i-1][0][x][y]+cal(j,1));
                            a[i][1][x][y]=min(a[i][1][x][y],a[i-1][1][x][y]+cal(j,1));
                        }
                continue;
            }
            if(s[i][j]>='a' && s[i][j]<='z')
            {
                for(int x=0;x<=1;x++)
                        for(int y=0;y<=1;y++)
                        {
                            a[i][x][1][y]=min(a[i][x][1][y],a[i-1][x][0][y]+cal(j,1));
                            a[i][x][1][y]=min(a[i][x][1][y],a[i-1][x][1][y]+cal(j,1));
                        }
                continue;
            }
           for(int x=0;x<=1;x++)
                        for(int y=0;y<=1;y++)
                        {
                            a[i][y][x][1]=min(a[i][y][x][1],a[i-1][y][x][0]+cal(j,1));
                            a[i][y][x][1]=min(a[i][y][x][1],a[i-1][y][x][1]+cal(j,1));
                        }
        }
    }
    int ans=0x3f3f3f3f;
    for(i=1;i<=m;i++)ans=min(ans,a[n][1][1][1]);
    printf("%d",ans);
    return 0;
}