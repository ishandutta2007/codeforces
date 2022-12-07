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

map<string,int> m;
char s[105];
int n,i,ans;
string ss;

int main()
{
    gets(s+1);
    n=strlen(s+1);
    for(i=n+1;i<=2*n-1;i++)s[i]=s[i-n];
    for(i=1;i<=n;i++)
    {
        ss="";
        for(int j=i;j<=i+n-1;j++)ss+=s[j];
        if(m[ss]>0)continue;
        m[ss]=1;ans++;
    }
    printf("%d",ans);
    return 0;
}