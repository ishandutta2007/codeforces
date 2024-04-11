#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int n;

const double PI = 3.14159265358979;

double dp[1<<20|5];

double f(double now, int x1, int y1, int deg)
{
    double a = atan((double)(x1-now)/y1);
    double deg1 = (double)deg * PI / 180.0;
    if(fabs(a - deg1) > PI/2.0 - 1e-8)return -1e8;
    double dx = y1 * tan(a - deg1);
    return x1 - dx;
}

int x[22], y[22], a[22];
int l, r;

int main()
{
    scanf("%d%d%d",&n,&l,&r);
    int i;
    for(i=0;i<n;i++)scanf("%d%d%d",x+i,y+i,a+i);
    for(i=0;i<1<<n;i++)dp[i] = -1e8;
    dp[0] = l;
    for(i=0;i<1<<n;i++){
        for(int j=0;j<n;j++){
            if(i&1<<j)continue;
            double tmp = f(dp[i],x[j],y[j],a[j]);
            if(tmp < -1e7){printf("%.10f",(double)r-l);return 0;}
            dp[i|1<<j] = max(dp[i|1<<j], tmp);
        }
    }
    double ans = min((double)r, dp[(1<<n)-1]);
    printf("%.10f",ans-l);
    return 0;
}