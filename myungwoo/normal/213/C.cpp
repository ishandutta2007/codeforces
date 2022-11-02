#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int yy[]={1,0},xx[]={0,1};
int N,A[301][301],D[2][301][301],ans=-1e9;
queue <pii> que[2];

int main()
{
    int i,j,k,t,y1,x1,y2,x2,v;
    pii q;
    scanf("%d",&N);
    for (i=1;i<=N;i++) for (j=1;j<=N;j++) scanf("%d",A[i]+j);
    for (i=1;i<=N;i++) for (j=1;j<=N;j++) D[0][i][j] = -1e9;
    que[0].push(pii(1,1)); D[0][1][1] = A[1][1];
    for (i=2;i<N+N;i++){
        t = i&1;
        for (j=1;j<=N;j++) for (k=1;k<=N;k++) D[!t][j][k] = -1e9;
        while (!que[t].empty()){
            q = que[t].front(); que[t].pop();
            for (j=0;j<2;j++) for (k=0;k<2;k++){
                y1 = q.first+yy[j], x1 = i-q.first+xx[j];
                y2 = q.second+yy[k], x2 = i-q.second+xx[k];
                if (y1 > N || x1 > N || y2 > N || x2 > N) continue;
                v = A[y1][x1];
                if (y1 != y2 || x1 != x2) v += A[y2][x2];
                if (D[!t][y1][y2] == -1e9) que[!t].push(pii(y1,y2));
                if (D[!t][y1][y2] < D[t][q.first][q.second]+v)
                    D[!t][y1][y2] = D[t][q.first][q.second]+v;
            }
        }
    }
    while (!que[0].empty()){
        q = que[0].front(); que[0].pop();
        if (ans < D[0][q.first][q.second])
            ans = D[0][q.first][q.second];
    }
    printf("%d",ans);
}