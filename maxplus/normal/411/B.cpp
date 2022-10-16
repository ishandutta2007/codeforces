#include <iostream>
#include <cstring>

using namespace std;

const int N = 101;

bool lck[N];
int b[N], d[N][N], lock[N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> d[i][j];

    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
            if (!lock[i] && d[i][j] != 0 && (b[d[i][j]] || lck[d[i][j]]))
            {
                lock[i] = j;
                if (lock[b[d[i][j]]] == 0)
                    lock[b[d[i][j]]] = j;
                lck[d[i][j]] = 1;
            }
            else if (!lock[i])
                b[d[i][j]] = i;
        memset(b, 0, sizeof(b));
    }

    for (int i = 1; i <= n; ++i)
        cout << lock[i] << '\n';
    return 0;
}