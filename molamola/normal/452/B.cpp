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

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(m <= n){
        if(m == 0)printf("%d %d\n%d %d\n%d %d\n%d %d",1,0,n,0,0,0,n-1,0);
        else{
        double a = sqrt(n*n+m*m) + 2*sqrt(n*n+(m-1)*(m-1));
        double b = 2*sqrt(n*n+m*m) + n;
        if(a > b)printf("%d %d\n%d %d\n%d %d\n%d %d",0,1,n,m,0,0,n,m-1);
        else printf("%d %d\n%d %d\n%d %d\n%d %d",0,0,n,m,0,m,n,0);
        }
    }
    else{
        if(n == 0)printf("%d %d\n%d %d\n%d %d\n%d %d",0,1,0,m,0,0,0,m-1);
        else{
        double a = sqrt(n*n+m*m) + 2*sqrt((n-1)*(n-1)+m*m);
        double b = 2*sqrt(n*n+m*m) + m;
        if(a > b)printf("%d %d\n%d %d\n%d %d\n%d %d",1,0,n,m,0,0,n-1,m);
        else printf("%d %d\n%d %d\n%d %d\n%d %d",0,0,n,m,n,0,0,m);
        }
    }
    return 0;
}