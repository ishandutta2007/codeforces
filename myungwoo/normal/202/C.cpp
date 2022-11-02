#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

int X,arr[99][99];
bool impossible[99][99],D[11][11][101][1024];

struct QUE{
    int y,x,k,m;
};
queue <QUE> que;

void iq(int y,int x,int k,int m)
{
    QUE q={y,x,k,m};
    if (D[q.y][q.x][q.k][q.m]) return;
    D[q.y][q.x][q.k][q.m] = 1;
    que.push(q);
}

bool proc(int n)
{
    int m=(n+1)/2,i,j,nxt;
    QUE q;
    for (i=1;i<=m;i++) for (j=1;j<=m;j++)
        arr[i][j] = 4, impossible[i][j] = 0;
    if (n&1){
        for (i=1;i<=m;i++)
            arr[i][m] = arr[m][i] = 2;
        arr[m][m] = 1;
    }else{
        for (i=1;i<=m;i++)
            impossible[i][m] =
            impossible[m][i] = 1;
    }
    memset(D,0,sizeof(D));
    while (!que.empty()) que.pop();
    iq(1,1,X,0);
    while (!que.empty()){
        q = que.front(); que.pop();
        if (q.k == 0) return 1;
        if (q.x > m)
            q.x = 1, q.y++;
        if (q.y > m) continue;
        if (!((q.m>>(q.x-1))&1) && !impossible[q.y][q.x] && q.k >= arr[q.y][q.x] &&
            (q.x == 1 || !((q.m>>(q.x-2))&1))){
                iq(q.y,q.x+1,q.k-arr[q.y][q.x],q.m|(1<<(q.x-1)));
        }
        if ((q.m>>(q.x-1))&1)
            nxt = q.m-(1<<(q.x-1));
        else nxt = q.m;
        iq(q.y,q.x+1,q.k,nxt);
    }
    return 0;
}

int main()
{
    int i;
    scanf("%d",&X);
    if (X == 1){ puts("1"); return 0; }
    for (i=3;;i++) if (proc(i)){ printf("%d\n",i); break; }
}