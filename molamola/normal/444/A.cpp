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

int x[505];
int a[250000], b[250000], c[250000];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;i++)scanf("%d",x+i);
    double ans = 0;
    for(i=1;i<=m;i++){
        scanf("%d%d%d",a+i,b+i,c+i);
    }
    for(i=1;i<=m;i++){
        ans = max(ans, (double)(x[a[i]] + x[b[i]]) / c[i]);
    }
    printf("%.10f",ans);
    return 0;
}