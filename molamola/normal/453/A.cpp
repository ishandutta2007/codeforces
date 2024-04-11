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

double pw(double x, int n)
{
    double res = 1;
    while(n){
        if(n & 1)res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main()
{
//  freopen("input.txt","r",stdin);
    int n, m;
    scanf("%d%d",&m,&n);
    double ans = m;
    for(int i=1;i<m;i++){
        ans -= pw((double)i/m, n);
    }
    printf("%.10f",ans);
    return 0;
}