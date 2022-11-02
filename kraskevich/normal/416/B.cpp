#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = 55555;
const int M = 5;

int t[N][M];
long long r[N];
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> t[i][j];
    fill(r, r + m, 0);
    for (int a = 0; a < n; a++)
        for (int p = 0; p < m; p++) {
            r[p] += t[p][a];
            if (p > 0)
                r[p] = max(r[p], r[p - 1] + t[p][a]);
        }
    for (int i = 0; i < m; i++)
        cout << r[i] << " ";


    return 0;
}