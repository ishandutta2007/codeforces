#include <stdio.h>
#include <queue>
using namespace std;

int yy[]={-1,0,1,0},xx[]={0,1,0,-1};
int N,M,ans=1e9;
char A[99][99];
bool V[99][99];

struct QUE{
    int y,x;
};
queue <QUE> que;

void iq(int y,int x)
{
    QUE q={y,x};
    que.push(q);
}

int bfs()
{
    int i,j,y,x,count=0;
    QUE q;
    for (i=1;i<=N;i++) for (j=1;j<=M;j++){
        V[i][j] = 0;
        if (A[i][j] == '#'){
            count++;
            if (que.empty()) V[i][j] = 1, iq(i,j);
        }
    }
    while (!que.empty()){
        q = que.front(); que.pop(); count--;
        for (i=0;i<4;i++){
            y = q.y+yy[i], x = q.x+xx[i];
            if (y < 1 || x < 1 || y > N || x > M || A[y][x] != '#' || V[y][x]) continue;
            V[y][x] = 1;
            iq(y,x);
        }
    }
    return count;
}

int main()
{
    int i,j,k,y,x,cnt;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) scanf("%s",A[i]+1);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (A[i][j] == '#'){
        cnt = 0;
        for (k=0;k<4;k++){
            y = i+yy[k], x = j+xx[k];
            if (y < 1 || x < 1 || y > N || x > M) continue;
            if (A[y][x] == '#') cnt++;
        }
        if (cnt == 2) ans = 2;
    }
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (A[i][j] == '#'){
        A[i][j] = '.';
        if (bfs()) ans = 1;
        A[i][j] = '#';
    }
    printf("%d",ans<1e9?ans:-1);
}