#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = 1000 * 1000 * 1000;
const int N = 1111;

int d[N][N][4];
string s[N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '*';      
}

struct State {
    int x;
    int y;
    int dir;

    State(int x_, int y_, int dir_): x(x_), y(y_), dir(dir_) {}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (s[i][j] == 'T') {
                ex = i;
                ey = j;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fill(d[i][j], d[i][j] + 4, INF);
    deque<State> q;
    for (int k = 0; k < 4; k++) {
        d[sx][sy][k] = 0;
        q.push_back(State(sx, sy, k));
    }
    while (q.size()) {
        State st = q.front();
        q.pop_front();
        for (int dd = 0; dd < 4; dd++) {
            int nx = st.x + dx[dd];
            int ny = st.y + dy[dd];
            if (!valid(nx, ny))
                continue;
            int w = (dd == st.dir ? 0 : 1);
            if (d[nx][ny][dd] > d[st.x][st.y][st.dir] + w) {
                d[nx][ny][dd] = d[st.x][st.y][st.dir] + w;
                if (w == 0)
                    q.push_front(State(nx, ny, dd));
                else       
                    q.push_back(State(nx, ny, dd));
            } 
        }
    }
    int res = *min_element(d[ex][ey], d[ex][ey] + 4);
    if (res <= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}