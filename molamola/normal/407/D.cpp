
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>

#define X first
#define Y second
typedef long long ll;

int p[440][440];
int n, m;
int nxt[160002][2];
short link[404][404][404];

inline short min(short x,short y){return x>y?x:y;}

int main()
{
    scanf("%d%d",&n,&m);
    int i, j, k, ans = 0;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",p[i]+j);
    for(i=1;i<=n;i++){
        for(k=1;k<=m;k++){
            if(nxt[p[i][k]][1] == -i)link[i][i][k] = nxt[p[i][k]][0];
            nxt[p[i][k]][0] = k;
            nxt[p[i][k]][1] = -i;
        }
        int tmp = 0, now = 0;
        for(k=1;k<=m;k++){
            now = std::max(now, (int)link[i][i][k]);
            tmp = std::max(tmp, k - now);
        }
        ans = std::max(ans, tmp);
    }
    for(i=1;i<n;i++){
        for(j=1;j+i<=n;j++){
            for(k=1;k<=m;k++){
                link[j][j+i][k] = min(link[j+1][j+i][k], link[j][j+i-1][k]);
            }
            int nd = n*i+j;
            for(k=1;k<=m;k++){
                if(p[j][k] == p[j+i][k])link[j][j+i][k] = k;
                if(nxt[p[j][k]][1] == nd){
                    link[j][j+i][k] = min(link[j][j+i][k], nxt[p[j][k]][0]);
                }
                if(nxt[p[j+i][k]][1] == nd){
                    link[j][j+i][k] = min(link[j][j+i][k], nxt[p[j+i][k]][0]);
                }
                nxt[p[j][k]][0] = k;
                nxt[p[j][k]][1] = nd;
                nxt[p[j+i][k]][0] = k;
                nxt[p[j+i][k]][1] = nd;
            }
            int tmp = 0, now = 0;
            for(k=1;k<=m;k++){
                now = std::max(now, (int)link[j][j+i][k]);
                tmp = std::max(tmp, k - now);
            }
            ans = std::max(ans, (i+1) * tmp);
            if(ans > 437){
                ans++;
                ans--;
            }
        }
    }
    printf("%d",ans);
    return 0;
}