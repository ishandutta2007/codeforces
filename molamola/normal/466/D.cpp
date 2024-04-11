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

int a[2020];
int p[2020];
ll ans = 1;

int main()
{
    //freopen("input.txt","r",stdin);
    int n, h, i;
    scanf("%d%d",&n,&h);
    for(i=1;i<=n;i++){
        scanf("%d",a+i);
        if(a[i] > h){printf("0");return 0;}
    }
    a[n+1] = h;
    int prev = 0;
    for(i=1;i<=n+1;i++){
        if(abs(h - a[i] - prev) > 1){
            printf("0");return 0;
        }
        p[i] = h - a[i] - prev;
        prev = h - a[i];
    }
    int cnt = 0;
    for(i=1;i<=n+1;i++){
        if(p[i] == -1)ans *= cnt--;
        if(p[i] == 0)ans *= (cnt+1);
        if(p[i] == 1)cnt++;
        ans %= 1000000007;
    }
    printf("%lld",ans);
    return 0;
}