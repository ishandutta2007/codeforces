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

double a, d;
int n;

int main()
{
    scanf("%lf%lf%d",&a,&d,&n);
    double now = 0;
    for(int i=0;i<n;i++){
        now = fmod(now + d, 4.0*a);
        double t = fmod(now, a);
        if(now < a)printf("%.9lf %.9lf\n", t, 0.0);
        else if(now < 2*a)printf("%.9lf %.9lf\n", a, t);
        else if(now < 3*a)printf("%.9lf %.9lf\n", a-t, a);
        else printf("%.9lf %.9lf\n",0.0, a-t);
    }
    return 0;
}