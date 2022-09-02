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
//  freopen("input.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==1 && m==1)printf("1.000000000");
    else printf("%.10f",(double)(2*n*m-n-m)/((double)n*(m*n-1)));
    return 0;
}