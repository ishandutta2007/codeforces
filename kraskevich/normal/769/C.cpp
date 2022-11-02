#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1000 * 1000 * 1000;
const int N = 1111;
const string I = "IMPOSSIBLE";

int n, m;
int k;
string s[N];
int dist[N][N];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool can_move(int x, int y) {
    return valid(x, y) && s[x][y] != '*';
}

const string DIR = "DLRU";
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};

int main() {
#if FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    cin >> n >> m >> k;
    if (k % 2 == 1) {
        cout << I << endl;
        return 0;
    }
    int sx = -1;
    int sy = -1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'X') {
                sx = i;
                sy = j;
            }
    }
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, INF);
    dist[sx][sy] = 0;
    queue<pii> q;
    q.push(pii(sx, sy));
    int diff = 0;
    while (q.size()) {
        pii v = q.front();
        q.pop();
        diff++;
        for (int d = 0; d < 4; d++) {
            int x = v.first + dx[d];
            int y = v.second + dy[d];
            if (can_move(x, y) && dist[x][y] > dist[v.first][v.second] + 1) {
                dist[x][y] = dist[v.first][v.second] + 1;
                q.push(pii(x, y));
            }
        }
    }
    if (diff == 1) {
        cout << I << endl;
        return 0;
    }
    string res;
    int reps = k;
    for (int i = 0; i < reps; i++) {
        int dd = -1;
        for (int d = 0; d < 4; d++) {
            int nx = sx + dx[d];
            int ny = sy + dy[d];
            if (can_move(nx, ny) && dist[nx][ny] < k) {
                dd = d;
                break;
            }
        }
        assert (dd >= 0);
        int nx = sx + dx[dd];
        int ny = sy + dy[dd];
        sx = nx;
        sy = ny;
        res += DIR[dd];
        k--;
    }
    cout << res << endl;
}