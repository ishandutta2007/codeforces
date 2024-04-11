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

#define Cache(x,y) (m*(x)+(y))

int xx[4] = {0,-1,0,1}, yy[4] = {-1,0,1,0};
int change[130];
int inp[2020][2020];
char ch[2020];
int n, m;
int Que[4000040];
bool chk[2020][2020];
int dis[2020][2020];
int ans[2];
int bak[2020][2020];

void bfs(int mode)
{
    int *fr = Que, *re = Que;
    int i, j;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(inp[i][j] == -1 && !chk[i][j])*fr++ = Cache(i,j), dis[i][j] = 0;
    while(fr!=re){
        int tmp = *re++;
        int x = tmp/m, y = tmp%m;
        for(i=0;i<4;i++){
            int tx = x+xx[i], ty = y+yy[i];
            if(tx<0 || ty<0 || tx>=n || ty>=m || chk[tx][ty])continue;
            if(inp[tx][ty] == (i^2)){
                *fr++ = Cache(tx,ty), bak[tx][ty] = tmp;
                if(dis[ans[0]][ans[1]] < (dis[tx][ty] = dis[x][y]+1)){
                    ans[0] = tx, ans[1] = ty;
                }
            }
        }
    }
    if(mode == 0 && re - Que != n * m){printf("-1");exit(0);}
}

int main()
{
    change['#'] = -1;
    change['<'] = 0;
    change['^'] = 1;
    change['>'] = 2;
    change['v'] = 3;
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<n;i++){
        scanf("%s",ch);
        for(j=0;j<m;j++)inp[i][j] = change[ch[j]];
    }
    bfs(0);
    int len = dis[ans[0]][ans[1]];
    while(inp[ans[0]][ans[1]] != -1){
        chk[ans[0]][ans[1]] = 1;
        int tmp = bak[ans[0]][ans[1]];
        ans[0] = tmp / m;
        ans[1] = tmp % m;
    }
    memset(dis,0,sizeof dis);
    bfs(1);
    if(len == dis[ans[0]][ans[1]])len<<=1;
    else len = 2*len - 1;
    printf("%d",len);
    return 0;
}