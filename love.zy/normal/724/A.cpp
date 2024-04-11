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

int a[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int i,n,p,q;

int find(string s)
{
    if(s=="monday")return 1;
    if(s=="tuesday")return 2;
    if(s=="wednesday")return 3;
    if(s=="thursday")return 4;
    if(s=="friday")return 5;
    if(s=="saturday")return 6;
    if(s=="sunday")return 7;
    return -1111;
}

int main()
{
    string s1,s2;
    cin>>s1;
    p=find(s1);
    cin>>s2;
    q=find(s2);
    q=(q+7-p)%7;
    for(i=1;i<=11;i++)
    {
        if(a[i]%7==q){printf("YES");return 0;}
    }
    printf("NO");
    return 0;
}