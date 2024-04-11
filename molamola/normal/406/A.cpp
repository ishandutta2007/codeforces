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

int p[1010][1010];

int main()
{
    int n, i, j, ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",p[i]+j);
    for(i=0;i<n;i++)ans += p[i][i];
    int q;
    scanf("%d",&q);
    while(q--){
        int t;
        scanf("%d",&t);
        if(t == 3)printf("%d",ans&1);
        else{
            int x;
            scanf("%d",&x);
            ans ++;
        }
    }
    return 0;
}