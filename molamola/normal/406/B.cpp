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

int n, p[500050];
int c[1000010];
int ans[1000010];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d",p+i);
    for(i=1;i<=n;i++)c[p[i]] = 1;
    int t = 0;
    for(i=1;i<=500000;i++){
        if(c[i] && c[1000001-i])t++;
    }
    for(i=1;i<=500000;i++){
        if(c[i] || c[1000001-i])continue;
        if(t == 0)break;
        ans[i] = ans[1000001-i] = 1;
        --t;
    }
    for(i=1;i<=1000000;i++){
        if(c[i]){
            if(c[1000001-i])continue;
            ans[1000001-i] = 1;
        }
    }
    printf("%d\n",n);
    for(i=1;i<=1000000;i++)if(ans[i])printf("%d ",i);
    return 0;
}