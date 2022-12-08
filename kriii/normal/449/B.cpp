#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct edge{
    edge(int y_, int c_, int p_){y = y_; c = c_; p = p_;}
    int y, c, p;
};

vector<edge> G[100010];
struct phase{
    phase(int x_, long long c_, int l_){x = x_; c = c_; l = l_;}
    int x; long long c; int l;

    bool operator <(const phase t)const{return c > t.c;}
};
priority_queue<phase> Q;

long long dist[100010];
int N,M,K,L[100010];

int main()
{
    scanf("%d %d %d",&N,&M,&K);
    for (int i=0;i<M;i++){
        int x,y,c;
        scanf ("%d %d %d",&x,&y,&c);
        G[x].push_back(edge(y,c,0));
        G[y].push_back(edge(x,c,0));
    }
    for (int i=1;i<=K;i++){
        int y,c; scanf ("%d %d",&y,&c);
        G[1].push_back(edge(y,c,1));
        G[y].push_back(edge(1,c,1));
    }

    for (int i=1;i<=N;i++) dist[i] = 1e16;
    Q.push(phase(1,0,0));
    for (int i=1;i<=N;i++) L[i] = 1;
    while (!Q.empty()){
        long long c = Q.top().c; int x = Q.top().x, l = Q.top().l; Q.pop();

        if (dist[x] < c) continue;
        if (dist[x] == c){
            if (l == 0) L[x] = 0; continue;
        }
        dist[x] = c;
        if (l == 0) L[x] = 0;
        for (auto p : G[x]){
            int y = p.y; long long nc = p.c + c;
            if (dist[y] >= nc) Q.push(phase(y,nc,p.p));
        }
    }

    int s = 0;
    for (int i=2;i<=N;i++) s += L[i];
    printf ("%d\n",K-s);

    return 0;
}