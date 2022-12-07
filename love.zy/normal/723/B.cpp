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
  
int i,j,k,l,m,n;
char s[500];

int main()
{
    scanf("%d\n",&n);
    gets(s);
    int m1=0,m2=0;
    m=0;l=0;
    for(i=0;i<n;i++)
    {
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')){m++;continue;}
        if(l>0 && m>0)m2++;
        if(l==0)m1=max(m1,m);
        if(s[i]=='(')l++;
        if(s[i]==')')l--;
        m=0;
    }
    m1=max(m1,m);
    printf("%d %d",m1,m2);
    return 0;
}