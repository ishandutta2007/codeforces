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

int d[100010], e[100010], p[100010];
int top;

int main()
{
    int n;
    scanf("%d",&n);
    if(n <= 2){printf("%d",n);return 0;}
    int i;
    for(i=0;i<n;i++)scanf("%d",p+i);
    int now = 1;
    for(i=1;i<n;i++){
        if(p[i] > p[i-1])now++;
        else now = 1;
        d[i] = now;
    }
    now = 1;
    for(i=n-2;i>=0;i--){
        if(p[i+1] > p[i])now++;
        else now = 1;
        e[i] = now;
    }
    d[0] = e[n-1] = 1;
    int ans = max(d[n-2], e[1]) + 1;
    for(i=2;i<n;i++){
        if(p[i] > p[i-2] + 1)ans = max(ans, d[i-2] + e[i] + 1);
        else ans = max(ans, max(d[i-2], e[i]) + 1);
    }
    printf("%d",ans);
    return 0;
}