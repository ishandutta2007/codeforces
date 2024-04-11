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

LL a[]={0,0,1,2,9};

LL C(int n,int k)
{
    LL r1=1,r2=1;
    for(int i=0;i<k;i++)r1*=1ll*(n-i);
    for(int i=2;i<=k;i++)r2*=1ll*i;
    return r1/r2;
}

int n,k;

int main()
{
    scanf("%d%d",&n,&k);
    LL sum=0;
    while(k--)sum+=C(n,k+1)*a[k+1];
    printf("%lld\n",sum+1);
    return 0;
}