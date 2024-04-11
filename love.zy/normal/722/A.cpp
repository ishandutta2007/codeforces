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
  
int a,b,n;

void print(int x)
{
    if(x<10)printf("0");
    printf("%d",x);
}

int main()
{
    scanf("%d",&n);
    scanf("%d:%d",&a,&b);
    if(n==12)
    {
        if(a>12){
            if(a%10!=0)a%=10;else a=10;}
        if(a<=0)a=1;
        print(a);
        printf(":");
        if(b>=60)
            b%=10;
        print(b);
        return 0;
    }
    if(n==24)
    {
        if(a>=24){
            if(a%10!=0)a%=10;else a=10;}
        print(a);
        printf(":");
        if(b>=60)b%=10;
        print(b);
        return 0;
    }
    return 0;
}