#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 3005;

int N, M;
int s1, t1, l1, s2, t2, l2;

array<int, MaxN> dist[MaxN];
vector<int> adj[MaxN];


void input(){
	scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
}

void bfs(int v, array<int, MaxN>& dst){
    static const int Infty = 10101010;
    fill(dst.begin(), dst.begin()+N+1, Infty);

    dst[v] = 0;
    queue<int> Q;
    Q.push(v);

    while(!Q.empty()){
        int w = Q.front(); Q.pop();

        for(int s: adj[w]){
            if(dst[s] == Infty){
                dst[s] = dst[w] + 1;
                Q.push(s);
            }
        }
    }
}

int main(){
	input();

    for(int v = 1; v <= N; v++){
        bfs(v, dist[v]);
    }

    if(dist[s1][t1] > l1 || dist[s2][t2] > l2){
        printf("-1\n");
        return 0;
    }

    int result = min(M, dist[s1][t1]+dist[s2][t2]);

//    printf("dist[1][1]=%d, dist[1][3]=%d, dist[3][3]=%d\n",
//            dist[1][1],dist[1][3],dist[3][3]);

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            int dist1a = dist[s1][a] + dist[a][b] + dist[b][t1],
                dist2a = dist[s2][a] + dist[a][b] + dist[b][t2],
                dist1b = dist[s1][b] + dist[b][a] + dist[a][t1],
                dist2b = dist[s2][b] + dist[b][a] + dist[a][t2];

            if(dist1a <= l1 && dist2a <= l2){
                int total = dist1a + dist2a - dist[a][b];
                result = min(result, total);
//                printf("A%d\n", result);
            }
            if(dist1a <= l1 && dist2b <= l2){
                result = min(result, dist1a+dist2b - dist[a][b]);
//                printf("dist1a=%d dist1b=%d dist2a=%d dist2b=%d\n", dist1a,
//                        dist1b, dist2a, dist2b);
//                printf("B%d (%d,%d)\n", result, a, b);
            }
            if(dist1b <= l1 && dist2a <= l2){
                result = min(result, dist1b+dist2a - dist[a][b]);
//                printf("C%d\n", result);
            }
            if(dist1b <= l1 && dist2b <= l2){
                result = min(result, dist1b+dist2b - dist[a][b]);
//                printf("D%d\n", result);
            }
        }
    }

    printf("%d\n", M-result);
}