#include<bits/stdc++.h>
using namespace std;
 
const int INF = 1e9 + 5;
const int INF8 = 120;
 
const int DIRS = 4;
const int DR[] = {-1,  0, +1,  0};
const int DC[] = { 0, +1,  0, -1};
 
const int NM_MAX = 1005;
const int K_MAX = 41;
 
int N, M, K, Q;
int A[NM_MAX][NM_MAX];
vector<pair<int, int>> color_list[K_MAX];
int8_t dist[K_MAX][NM_MAX][NM_MAX];
bool finished_color[K_MAX];
 
bool valid(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < M;
}
 
void bfs_check(queue<pair<int, int>> &q, int color, pair<int, int> s, int new_dist) {
    if (new_dist < dist[color][s.first][s.second]) {
        dist[color][s.first][s.second] = new_dist;
        q.push(s);
    }
}
 
void bfs(int color) {
    queue<pair<int, int>> q;
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            dist[color][i][j] = INF8;
 
            if (A[i][j] == color)
                bfs_check(q, color, {i, j}, 0);
        }
 
    memset(finished_color, false, sizeof(finished_color));
 
    while (!q.empty()) {
        pair<int, int> top = q.front(); q.pop();
        int r = top.first, c = top.second;
 
        if (!finished_color[A[r][c]]) {
            for (auto &pr : color_list[A[r][c]])
                bfs_check(q, color, pr, dist[color][r][c] + 1);
 
            finished_color[A[r][c]] = true;
        }
 
        for (int dir = 0; dir < DIRS; dir++) {
            int nr = r + DR[dir];
            int nc = c + DC[dir];
 
            if (valid(nr, nc))
                bfs_check(q, color, {nr, nc}, dist[color][r][c] + 1);
        }
    }
 
    // cerr << color + 1 << ":" << endl;
 
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < M; j++)
    //         cerr << (int) dist[color][i][j] << (j < M - 1 ? ' ' : '\n');
 
    // cerr << endl;
}
 
int query(int r1, int c1, int r2, int c2) {
    int color1 = A[r1][c1];
    int color2 = A[r2][c2];
    int answer = min(dist[color1][r2][c2] + 1, dist[color2][r1][c1] + 1);
    answer = min(answer, abs(r1 - r2) + abs(c1 - c2));
    vector<int> closest(K, INF);
    int goal = answer - 1;
 
    for (int r = max(r1 - goal, 0); r <= min(r1 + goal, N - 1); r++)
        for (int c = max(c1 - goal, 0); c <= min(c1 + goal, M - 1); c++)
            closest[A[r][c]] = min(closest[A[r][c]], abs(r - r1) + abs(c - c1));
 
    for (int color = 0; color < K; color++)
        answer = min(answer, closest[color] + 1 + dist[color][r2][c2]);
 
    return answer;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> N >> M >> K;
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            A[i][j]--;
            color_list[A[i][j]].emplace_back(i, j);
        }
 
    for (int color = 0; color < K; color++)
        bfs(color);
 
    cin >> Q;
 
    for (int q = 0; q < Q; q++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        cout << query(r1, c1, r2, c2) << '\n';
    }
}