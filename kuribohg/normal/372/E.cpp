#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=1010;
const double eps=1e-9;
const int MOD=1000000007;
int n,tot,L,R;
double x[MAXN],y[MAXN];
LL A,B,C,D,ans;
inline bool E(double a,double b){return fabs(a-b)<eps;}
struct Node
{
    double x,y,k;
    friend bool operator<(const Node &p,const Node &q)
    {
        return E(p.x,q.x)?(E(p.y,q.y)?(p.k<q.k):(p.y<q.y)):(p.x<q.x);
    }
}a[MAXN*MAXN];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>A>>B>>C>>D;
        //x[i]=A*1.0/B;
        //y[i]=C*1.0/D;
        x[i]=A*B*D*D*1.0/(A*A*D*D+B*B*C*C);
        y[i]=C*D*B*B*1.0/(A*A*D*D+B*B*C*C);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            a[++tot].x=x[i]+x[j],a[tot].y=y[i]+y[j];
            if(E(x[i],x[j])) a[tot].k=1e20;
            else a[tot].k=(y[i]-y[j])/(x[i]-x[j]);
        }
    sort(a+1,a+tot+1);
    L=1;
    while(L<=tot)
    {
        R=L;
        while(R<=tot&&E(a[R+1].x,a[R].x)&&E(a[R+1].y,a[R].y)) R++;
        LL c=1,con=1;
        for(int i=L+1;i<=R;i++)
        {
            if(E(a[i].k,a[i-1].k)) c++;
            else con=(con*(c+1))%MOD,c=1;
        }
        con=(con*(c+1))%MOD;
        ans=(ans+con+(LL)L-(LL)R-2LL+MOD)%MOD;
        L=R+1;
    }
    printf("%I64d\n",ans);
    return 0;
}