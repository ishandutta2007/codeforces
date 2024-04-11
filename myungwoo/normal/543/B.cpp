#include <bits/stdc++.h>
using namespace std;

#define MAXN 3003
#define pb push_back

int N, M, S1, T1, L1, S2, T2, L2;
int D[3003][3003];
vector <int> con[3003];

void bfs(int s, int dist[3003])
{
    queue <int> que;
    for (int i=1;i<=N;i++) dist[i] = 2e9;
    dist[s] = 0; que.push(s);
    while (!que.empty()){
        int q = que.front(); que.pop();
        for (int t: con[q]) if (dist[t] == 2e9){
            dist[t] = dist[q]+1; que.push(t);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i=1;i<=M;i++){
        int a, b;
        cin >> a >> b;
        con[a].pb(b); con[b].pb(a);
    }
    cin >> S1 >> T1 >> L1;
    cin >> S2 >> T2 >> L2;
    for (int i=1;i<=N;i++) bfs(i, D[i]);
    if (D[S1][T1] > L1 || D[S2][T2] > L2){ puts("-1"); return 0; }
    int ans = D[S1][T1] + D[S2][T2];
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) if (i != j){
        if (D[S1][i] + D[i][j] + D[j][T1] <= L1 && D[S2][i] + D[i][j] + D[j][T2] <= L2)
            ans = min(ans, D[S1][i] + D[S2][i] + D[i][j] + D[j][T1] + D[j][T2]);
        if (D[S1][i] + D[i][j] + D[j][T1] <= L1 && D[T2][i] + D[i][j] + D[j][S2] <= L2)
            ans = min(ans, D[S1][i] + D[T2][i] + D[i][j] + D[j][T1] + D[j][S2]);
    }
    printf("%d\n", M - ans);
}