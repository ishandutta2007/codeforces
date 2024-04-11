
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
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

LL n,k,m;

LL cal(LL x)
{
    return (x*(x-1))>>1;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    if(k==0)
    {
        for(int i=1;i<=n;i++)printf("()");
        printf("\n");return 0;
    }
    if(k>cal(n)){printf("Impossible\n");return 0;}
    for(LL i=n;i>=1;i--)
        if(k<=cal(i) && k>cal(i-1)){m=i;break;}
    for(int i=1;i<=n-m;i++)printf("()");
    LL t=k-cal(m-1);
    for(LL i=1;i<=t+1;i++)printf("(");
    printf(")");
    for(int i=1;i<=m-t-1;i++)printf("(");
    for(int i=1;i<=m-1;i++)printf(")");
    printf("\n");
    return 0;
}