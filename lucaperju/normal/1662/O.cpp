#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define dbg(x) cerr << #x << " " << x << "\n"

void fastIOS() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

const int maxo = 360, maxr = 20;
int n;
bool wallC[1 + maxr][maxo];
bool wallS[1 + maxr][maxo];
bool vis[1 + maxr][maxo];

void visitCell(int r, int o, queue <pair <int, int>> &q) {
    if (r >= 0 && o >= 0 && o < maxo && not vis[r][o]) {
        vis[r][o] = true;
        q.push({r, o});
    }
}

void clean() {
    for (int i = 0; i <= maxr; i++)
        for (int o = 0; o < maxo; o++)
            wallC[i][o] = wallS[i][o] = vis[i][o] = false;
}

void solveTest() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char type;
        cin >> type;
        if (type == 'C') {
            int r, o1, o2;
            cin >> r >> o1 >> o2;
            for (int o = o1; o != o2; o = (o + 1) % maxo)
                wallC[r][o] = true;
        }
        else {
            int r1, r2, o;
            cin >> r1 >> r2 >> o;
            for (int r = r1; r < r2; r++)
                wallS[r][o] = true;
        }
    }
    queue <pair <int, int>> q;
    for (int o = 0; o < maxo; o++)
        visitCell(maxr, o, q);
    while (q.size()) {
        int r, o;
        tie(r, o) = q.front();
        q.pop();
        if (not wallC[r][o])
            visitCell(r - 1, o, q);
        if (r < maxr && not wallC[r + 1][o])
            visitCell(r + 1, o, q);
        if (not wallS[r][o])
            visitCell(r, (o - 1 + maxo) % maxo, q);
        if (not wallS[r][(o + 1) % maxo])
            visitCell(r, (o + 1) % maxo, q);
    }
    bool succes = false;
    for (int o = 0; o < maxo; o++)
        succes |= vis[0][o];
    if (succes)
        cout << "YES\n";
    else
        cout << "NO\n";
    clean();
}

int main() {
    fastIOS();
    int t;
    cin >> t;
    while (t--)
        solveTest();
    return 0;
}