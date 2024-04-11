
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAX_N = 1005;
int n, m, k, x, y;
string str;
bool arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];

void dfs(int x, int y) {
    visited[x][y] = true;
    int a = 0;
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(abs(dx) + abs(dy) == 1) {
                if(arr[x + dx][y + dy]) {
                    a++;
                }else if(!visited[x + dx][y + dy]) {
                    dfs(x + dx, y + dy);
                    a += ans[x + dx][y + dy];
                }
            }
        }
    }
    ans[x][y] = a;
}
void dfs2(int x, int y, int a) {
    visited[x][y] = true;
    ans[x][y] = a;
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(abs(dx) + abs(dy) == 1) {
                if(!arr[x + dx][y + dy] && !visited[x + dx][y + dy]) {
                    dfs2(x + dx, y + dy, a);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            arr[i][j] = (str[j] == '*');
        }
    }
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && !arr[i][j]) {
                dfs(i, j);
                v.push_back({i, j});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < (int) v.size(); i++) {
        dfs2(v[i].first, v[i].second, ans[v[i].first][v[i].second]);
    }
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        cout << ans[x - 1][y - 1] << endl;
    }
}