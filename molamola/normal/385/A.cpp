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

int x[110];
int n,c;

int main()
{
    scanf("%d%d",&n,&c);
    int i;
    for(i=1;i<=n;i++)scanf("%d",x+i);
    int ans = 0;
    for(i=2;i<=n;i++){
        ans = max(ans, x[i-1] - x[i]);
    }
    if(ans <= c)ans = 0;
    else ans -= c;
    printf("%d",ans);
    return 0;
}