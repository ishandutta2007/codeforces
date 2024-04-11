#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <ios>
#include <cstring>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 75;

int n, st[3];
char mat[MAXN][MAXN];

struct data {
    int a, b, c, d, e, f;

    data() {}
    data(int a, int b, int c, int d, int e, int f) : d(d), e(e), f(f) {
        int arr[3] = {a, b, c};
        sort(arr, arr + 3);
        this->a = arr[0], this->b = arr[1], this->c = arr[2];
    }
};

int dist[MAXN][MAXN][MAXN], move[MAXN][MAXN][MAXN][2];

queue<data> pq;

void add(int i, int a, int b, int c, int d) {
    if (mat[b][c] != mat[a][i]) return;
    pq.push(data(i, b, c, d+1, a+1, i+1));
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> st[0] >> st[1] >> st[2];
    sort(st, st + 3);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> mat[i][j];

    pq.push(data(st[0]-1, st[1]-1, st[2]-1, 0, -1, -1));

    memset(dist, -1, sizeof(dist));

    while (!pq.empty()) {
        data d = pq.front(); pq.pop();
        if (dist[d.a][d.b][d.c] != -1) continue;
        dist[d.a][d.b][d.c] = d.d;
        move[d.a][d.b][d.c][0] = d.e;
        move[d.a][d.b][d.c][1] = d.f;

        if (d.a == 0 && d.b == 1 && d.c == 2) break;

        for (int i=0; i<n; i++) {
            if (i == d.a || i == d.b || i == d.c) continue;

            add(i, d.a, d.b, d.c, d.d);
            add(i, d.b, d.a, d.c, d.d);
            add(i, d.c, d.a, d.b, d.d);
        }
    }

    if (dist[0][1][2] == -1) {
        cout << "-1\n";
        return 0;
    }

    cout << dist[0][1][2] << '\n';

    stack<pii> stk;
    int cur[3] = {0, 1, 2};

    while (move[cur[0]][cur[1]][cur[2]][0] != -1) {
        int a = move[cur[0]][cur[1]][cur[2]][0];
        int b = move[cur[0]][cur[1]][cur[2]][1];

        stk.push(pii(a, b));

        int arr[3] = {cur[0], cur[1], cur[2]};

        for (int i=0; i<3; i++)
            if (arr[i] == b-1)
                arr[i] = a-1;

        sort(arr, arr + 3);

        for (int i=0; i<3; i++) cur[i] = arr[i];
    }

    while (!stk.empty()) {
        cout << stk.top().first << ' ' << stk.top().second << '\n';
        stk.pop();
    }

    return 0;
}