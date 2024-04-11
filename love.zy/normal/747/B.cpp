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

char s[300];
map<char,int> m;
int i,n;

int main()
{
    scanf("%d\n",&n);
    gets(s+1);
    for(i=1;i<=n;i++)m[s[i]]++;
    if(n%4!=0){printf("===");return 0;}
    if(m['A']>n/4 || m['C']>n/4 || m['G']>n/4 || m['T']>n/4){printf("===");return 0;}
    for(i=1;i<=n;i++)
    {
        if(s[i]!='?')continue;
        if(m['A']<n/4){s[i]='A';m['A']++;continue;}
        if(m['C']<n/4){s[i]='C';m['C']++;continue;}
        if(m['G']<n/4){s[i]='G';m['G']++;continue;}
        if(m['T']<n/4){s[i]='T';m['T']++;continue;}
    }
    printf("%s",s+1);
    return 0;
}