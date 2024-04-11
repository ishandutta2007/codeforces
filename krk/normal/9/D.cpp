#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 36;

int n, h;
ll ways[Maxn][Maxn];

int main()
{
    cin >> n >> h;
    ways[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            for (int li = 0; li < i; li++) {
                int ri = i - 1 - li;
                for (int tj = 0; tj < j - 1; tj++)
                   ways[i][j] += ways[li][tj] * ways[ri][j - 1] + 
                                 ways[li][j - 1] * ways[ri][tj];
                ways[i][j] += ways[li][j - 1] * ways[ri][j - 1];
            }
        }
    ll res = 0;
    for (int i = h; i <= n; i++)
        res += ways[n][i];
    cout << res << endl;
    return 0;
}