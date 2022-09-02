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

int n, k;
int ans[100010];

int main()
{
    scanf("%d%d",&n,&k);
    if(n==1 && k!=0){printf("-1");return 0;}
    if(n/2 > k){printf("-1");return 0;}
    int t = n/2;
    int r = k - t + 1;
    int i;
    ans[0] = r, ans[1] = r*2;
    int now = 1;
    for(i=1;i<t;i++){
        while(!(now != r && now+1 != r && now != 2*r && now+1 != r*2))now++;
        ans[2*i] = now;
        ans[2*i+1] = ++now;
        now++;
    }
    if(n&1)ans[n-1] = 1e9 - 1;
    for(i=0;i<n;i++)printf("%d ",ans[i]);
    return 0;
}