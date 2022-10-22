#include <iostream>
using namespace std;

const int Maxn = 55;

int n;
int deg[Maxn];
bool bet[Maxn][Maxn];
int taken[2], cnt;

int main()
{
    cin >> n;
    for (int i = 0; i < n * (n - 1) / 2 - 1; i++) {
        int a, b; cin >> a >> b;
        bet[a][b] = true;
        deg[a]++; deg[b]++;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                bet[i][j] = bet[i][j] || bet[i][k] && bet[k][j];
    for (int i = 1; i <= n; i++)
        if (deg[i] < n - 1) taken[cnt++] = i;
    if (bet[taken[0]][taken[1]]) cout << taken[0] << " " << taken[1] << endl;
    else cout << taken[1] << " " << taken[0] << endl;
    return 0;
}