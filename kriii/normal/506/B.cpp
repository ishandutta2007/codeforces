#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[100001],R[100001];
int tp,ed[100001]; bool chk[100001];
int gc,grp[100001],gs[100001],gz[100001];

void dfs(int x)
{
    chk[x] = 1;
    for (int y : G[x]) if (!chk[y]) dfs(y);
    ed[tp++] = x;
}

int ans = 0;
void bfs(int x)
{
    queue<int> Q;

    Q.push(x); chk[x] = 1; int sz = 0;
    while (!Q.empty()){
        int x = Q.front(); Q.pop(); sz++;
        for (int y : R[x]) if (!chk[y]){
            Q.push(y); chk[y] = 1;
        }
    }
    if (sz > 1) gz[grp[x]]++;
}

int main()
{
    int N,M;

    scanf ("%d %d",&N,&M); while (M--){
        int x,y; scanf ("%d %d",&x,&y);
        G[x].push_back(y);
        R[y].push_back(x);
    }

    for (int i=1;i<=N;i++) if (!chk[i]) dfs(i);
    
    for (int i=1;i<=N;i++) chk[i] = 0;
    for (int i=1;i<=N;i++) if (!chk[i]){
        queue<int> Q;

        Q.push(i); chk[i] = 1;
        while (!Q.empty()){
            gs[gc]++;
            int x = Q.front(); Q.pop(); grp[x] = gc;
            for (int y : R[x]) if (!chk[y]){
                Q.push(y); chk[y] = 1;
            }
            for (int y : G[x]) if (!chk[y]){
                Q.push(y); chk[y] = 1;
            }
        }
        gz[gc] = gs[gc]-1;
        gc++;
    }

    for (int i=1;i<=N;i++) chk[i] = 0;
    for (int i=N-1;i>=0;i--) if (!chk[ed[i]]) bfs(ed[i]);

    for (int i=0;i<gc;i++){
        if (gs[i] > gz[i]) ans += gz[i];
        else ans += gs[i];
    }
    printf ("%d\n",ans);

    return 0;
}