#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 3333;

int ans;
int aa;
int ab;
int ac;
int ad;
vector<int> dist_r[N];
vector<int> dist[N];
vector<int> g[N];
vector<int> gr[N];
vector<int> two_max[N];
vector<int> two_max_r[N];
int n, m;

void upd_ans(int a, int b, int c, int d) {
    int cur = dist[a][b] + dist[b][c] + dist[c][d];
    if (cur > ans) {
        ans = cur;
        aa = a;
        ab = b;
        ac = c;
        ad = d;
    }
}

void print_ans() {
    vector<int> ans_v{aa, ab, ac, ad};
    for (int v : ans_v)
        cout << v + 1 << " ";
    cout << "\n";
}

void bfs(int st) {
    dist[st].assign(n, N);
    dist[st][st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v])
            if (dist[st][to] > dist[st][v] + 1) {
                dist[st][to] = dist[st][v] + 1;
                q.push(to);
            }
    }
    two_max[st].assign(3, -1);
    for (int i = 0; i < n; i++) {
        if (i == st || dist[st][i] == N)
            continue;
        if (two_max[st][0] == -1 || dist[st][two_max[st][0]] <= dist[st][i]) {
            two_max[st][2] = two_max[st][1];
            two_max[st][1] = two_max[st][0];
            two_max[st][0] = i;
        } else if (two_max[st][1] == -1 || dist[st][two_max[st][1]] <= dist[st][i]) {
            two_max[st][2] = two_max[st][1];
            two_max[st][1] = i;
        } else if (two_max[st][2] == -1 || dist[st][two_max[st][2]] <= dist[st][i]) {
            two_max[st][2] = i;
        }
    }
} 

void bfs_rev(int st) {
    dist_r[st].assign(n, N);
    dist_r[st][st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : gr[v])
            if (dist_r[st][to] > dist_r[st][v] + 1) {
                dist_r[st][to] = dist_r[st][v] + 1;
                q.push(to);
            }
    }
    two_max_r[st].assign(3, -1);
    for (int i = 0; i < n; i++) {
        if (i == st || dist_r[st][i] == N)
            continue;
        if (two_max_r[st][0] == -1 || dist_r[st][two_max_r[st][0]] <= dist_r[st][i]) {
            two_max_r[st][2] = two_max_r[st][1];
            two_max_r[st][1] = two_max_r[st][0];
            two_max_r[st][0] = i;
        } else if (two_max_r[st][1] == -1 || dist_r[st][two_max_r[st][1]] <= dist_r[st][i]) {
            two_max_r[st][2] = two_max_r[st][1];
            two_max_r[st][1] = i;
        } else if (two_max_r[st][2] == -1 || dist_r[st][two_max_r[st][2]] <= dist_r[st][i]) {
            two_max_r[st][2] = i;
        }
    }
} 
    

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        bfs(i);
        bfs_rev(i);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (dist[i][j] == N)
                continue;
            for (int x = 0; x < 3; x++)
                for (int y = 0; y < 3; y++) {
                    if (two_max_r[i][x] == -1 || two_max_r[i][x] == j)
                        continue;
                    if (two_max[j][y] == -1 || two_max[j][y] == i)
                        continue;
                    if (two_max_r[i][x] == two_max[j][y])
                        continue;
                    upd_ans(two_max_r[i][x], i, j, two_max[j][y]);
                }
        }
    print_ans();
}