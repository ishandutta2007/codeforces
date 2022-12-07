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
int i,j,k,l,m,n;
int best,worst;

int main()
{
    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
        k=s[i].length();
        a[k]++;
    }
    cin>>s[0];
    l=0;
    for(i=1;i<=n;i++)if(s[i]==s[0])l++;
    k=s[0].length();
    for(i=1;i<k;i++)best+=a[i];
    worst=best+a[k];
    best++;worst=worst-l+1;
    best+=((best-1)/m)*5;
    worst+=((worst-1)/m)*5;
    printf("%d %d",best,worst);
    return 0;
}