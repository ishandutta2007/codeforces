
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

int n,x,y,c;
bool f=true;

int main()
{
    scan(n);scan(x);scan(y);
    n-=2;c=y-x;x=y;
    while(n--)
    {
        scan(x);
        if(!f)
        {
            y=x;
            continue;
        }
        if(x-y!=c)
        {
            f=false;
            c=0;
        }
        y=x;
    }
    printf("%d\n",c+x);
    return 0;
}