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

int d[4040][1010];

double p[4040];
int k, l[4040];

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n*2;i++)scanf("%lf",p+i);
    for(i=0;i<n*2;i++){
        double x = p[i];
        int y = (int)(1000*x + 1e-8);
        y %= 1000;
        if(y == 0)continue;
        l[++k] = y;
    }
    int sum = 0, ans = 1e8;
    for(i=1;i<=k;i++)sum += l[i];
    for(int j=max(0,k-n);j<=min(n,k);j++)ans = min(ans, abs(sum-1000*j));
    double t = (double)ans / 1000 + 1e-10;
    printf("%.3f",t);
    return 0;
}