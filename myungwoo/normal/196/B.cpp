#include <stdio.h>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int yy[]={-1,0,1,0},xx[]={0,1,0,-1};
int N,M,K,SY,SX;
char map[1504][1504];
pii V[1504][1504];

struct QUE{
    int y,x;
};
queue <QUE> que;

void iq(int y,int x)
{
    QUE q={y,x};
    que.push(q);
}

bool bfs()
{
    int i,y,x,ny,nx;
    QUE q;
    iq(SY+N*M,SX+N*M);
    while (!que.empty()){
        q = que.front(); que.pop();
        for (i=0;i<4;i++){
            y = q.y+yy[i], x = q.x+xx[i];
            ny = y%N, nx = x%M;
            if (map[ny][nx] == '#' || V[ny][nx] == pii(y,x)) continue;
            if (V[ny][nx].first != -1)
                return 1;
            V[ny][nx] = pii(y,x);
            iq(y,x);
        }
    }
    return 0;
}

int main()
{
    int i,j;
    scanf("%d%d",&N,&M);
    for (i=0;i<N;i++){
        scanf("%s",map[i]);
        for (j=0;j<M;j++){
            V[i][j].first = -1;
            if (map[i][j] == 'S') SY = i, SX = j;
        }
    }
    if (bfs()) puts("Yes");
    else puts("No");
}