#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> PLL;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

#ifdef TEST
    class Timer
    {
    public:
        Timer()
        {
            start = clock();
        }

        ~Timer()
        {
            cerr << "Execution time: " << clock() - start << " ms" << endl;
        }
    private:
        int start;
    };

    Timer timer;
#endif

const int N = 1111;

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, 1, -1};
int f[4];

int row[N][N];
int col[N][N];
int s[N][N];
int n, m;

bool good_row(int r, int lo, int hi)
{
    if (lo > hi)
        swap(lo, hi);
    return (row[r][hi] - row[r][lo - 1]) == 0;
}

bool good_col(int r, int lo, int hi)
{
    if (lo > hi)
        swap(lo, hi);
    return (col[r][hi] - col[r][lo - 1]) == 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j < m; j++)
            if (st[j] == '1')
                s[i][j + 1] = 1;
    }
    for (int r = 0; r <= n; r++)
        for (int j = 1; j <= m; j++)
            row[r][j] = s[r][j] + row[r][j - 1];
    for (int c = 0; c <= m; c++)
        for (int i = 1; i <= n; i++)
            col[c][i] = s[i][c] + col[c][i - 1];
    int res1 = 0;
    int res2 = 0;
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++)
        {
            if (s[r][c] == 1)
                continue;
            for (int d = 0; d < 4; d++)
            {
                int j = 0;
                for (;;)
                {
                    j++;
                    int x = r + j * dx[d];
                    int y = c + j * dy[d];
                    if (x < 1 || x > n || y < 1 || y > m)
                        break;
                    if (s[x][y] == 1)
                        break;
                }
                j--;
                f[d] = j;
            }
            for (int l = 1; l <= min(f[0], f[1]); l++)
                if (good_row(r - l, c - l, c + l))
                    res1++;
            for (int l = 1; l <= min(f[1], f[2]); l++)
                if (good_col(c + l, r - l, r + l))
                    res1++;
            for (int l = 1; l <= min(f[2], f[3]); l++)
                if (good_row(r + l, c - l, c + l))
                    res1++;
            for (int l = 1; l <= min(f[0], f[3]); l++)
                if (good_col(c - l, r - l, r + l))
                    res1++;
            for (int d = 0; d < 4; d++)
                for (int l = 1; l <= f[d]; l++)
                {
                    if (good_row(r, c + dy[d] * l, c) && good_col(c + dy[d] * l, r + dx[d] * l, r))
                        res2++;
                    if (good_row(r + dx[d] * l, c + dy[d] * l, c) && good_col(c, r + dx[d] * l, r))
                        res2++;
                }
        }
    cout << res1 + res2 / 2;

    return 0;
}