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

int d[1010][1010];
char inp[1010][12][12];
int now[1010];
int chk[1010];
int pre[1010];
int an[1010][2], top;

int main()
{
    int n, m, k, w;
    scanf("%d%d%d%d",&n,&m,&k,&w);
    int i, j, u;
    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++){
            char ch[12];
            scanf("%s",ch+1);
            for(u=1;u<=m;u++){
                inp[i][j][u] = ch[u];
            }
        }
    }
    for(i=1;i<k;i++){
        for(j=i+1;j<=k;j++){
            int cnt = 0;
            int u, y;
            for(u=1;u<=n;u++){
                for(y=1;y<=m;y++){
                    if(inp[i][u][y] != inp[j][u][y])cnt++;
                }
            }
            d[i][j] = d[j][i] = cnt * w;
        }
    }
    for(i=1;i<=k;i++)d[0][i] = d[i][0] = n*m;
//  for(i=0;i<=k;i++){for(j=0;j<=k;j++)printf("%d ",d[i][j]);puts("");}
    chk[0] = 1;
    int v = 0, ans = 0;
    for(i=1;i<=k;i++)now[i] = ~0u>>1, pre[i] = -1;
    for(i=0;i<=k-1;i++){
        for(j=0;j<=k;j++){
            if(chk[j])continue;
            if(now[j] > d[v][j])now[j] = d[v][j], pre[j] = v;
        }
        int mn = -1;
        for(j=0;j<=k;j++){
            if(chk[j])continue;
            if(mn == -1 || now[mn] > now[j])mn = j;
        }
        an[top][0] = mn, an[top++][1] = pre[mn];
        ans += now[mn];
        v = mn;
        chk[v] = 1;
    }
    printf("%d\n",ans);
    for(i=0;i<top;i++)printf("%d %d\n",an[i][0],an[i][1]);
    return 0;
}