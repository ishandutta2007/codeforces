
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-7;
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

const int maxn=60005;
struct node
{
    double pos,v;
}p[maxn];
int n;

bool check(double t)
{
    double ma=-2e18,mi=2e18;
    for(int i=1;i<=n;i++)
    {
        ma=max(ma,p[i].pos-p[i].v*t);
        mi=min(mi,p[i].pos+p[i].v*t);
    }
    return ma<=mi+eps;
}

int main()
{
    double l=0,r=1e9;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf",&p[i].pos);
    for(int i=1;i<=n;i++)scanf("%lf",&p[i].v);
    while(abs(r-l)>eps)
    {
        double mid=(l+r)/2.0;
        if(check(mid))r=mid;else l=mid;
    }
    printf("%.10lf\n",r);
    return 0;
}