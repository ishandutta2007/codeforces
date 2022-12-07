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
  
int n,i,ans,x,y,lx,ly;
string s;

int main()
{
    cin>>n;
    cin>>s;lx=ly=-5;
    i=0;
    while(i<n)
    {
        x=y=0;
        while(i<n)
        {
            if(s[i]=='U')
            {
                if(y>=0){y=1;i++;continue;}else break;
            }
            if(s[i]=='D')
            {
                if(y<=0){y=-1;i++;continue;}else break;
            }
            if(s[i]=='R')
            {
                if(x>=0){x=1;i++;continue;}else break;
            }
            if(s[i]=='L')
            {
                if(x<=0){x=-1;i++;continue;}else break;
            }
        }
        ans++;
    }
    printf("%d",ans);
    return 0;
}