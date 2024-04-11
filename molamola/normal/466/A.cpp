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

int main()
{
//freopen("input.txt","r",stdin);
    int m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if(a*m < b)printf("%d",n*a);
    else printf("%d",min((n/m) * b + (n - m * (n/m)) * a, (n/m+1)*b));
    return 0;
}