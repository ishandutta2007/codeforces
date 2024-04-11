#include <iostream>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int n, m;
char a[505][505];
int used[505][505];
int kol(int x, int y) {
    int res = 0;
    for (int i = 0; i < 4; i++)
        res += (a[x + dx[i]][y + dy[i]] == '*');
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int px = 0, py = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '*' && kol(i, j) == 4)
                px = i, py = j;
    if (px + py == 0) {
        cout << "NO";
        return 0;
    }
    used[px][py] = 1;
    for (int i = px; a[i][py] == '*' && i <= n; i++)
        used[i][py] = 1;
    for (int i = px; a[i][py] == '*' && i > 0; i--)
        used[i][py] = 1;
    for (int i = py; a[px][i] == '*' && i <= m; i++)
        used[px][i] = 1;
    for (int i = py; a[px][i] == '*' && i > 0; i--)
        used[px][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '*' && !used[i][j])
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}