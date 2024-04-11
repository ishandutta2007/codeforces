
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
LL ts,tf,t;
int n;
LL a[100005];

int main()
{
    scanf("%lld%lld%lld",&ts,&tf,&t);
    scanf("%d",&n);tf-=t;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    LL ans=ts,aa=0;
    LL o=ts;a[0]=ts-t;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>tf)break;
        if(o-a[i]+1<ans)
        {
            ans=o-a[i]+1;
            aa=a[i]-1;
        }
        LL num=0,temp=a[i];
        while(a[i]==temp && i<=n){num++;i++;}
        i--;
        o=max(o+num*t,temp+num*t);
        if(o>tf)break;
    }
    if(o<=tf)aa=o;
    printf("%lld",aa);
    return 0;
}