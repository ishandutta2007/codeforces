#include <bits/stdc++.h>

using namespace std;

const int N = 2222;
int L = 100 * 1000 + 10;

int a[N][N];
int n, m, k, s;
vector<int> x[10], y[10];

int dx[4] = {1, 1, -1, -1};
int dy[4] = {-1, 1, 1, -1};

int absll(int x)
{
    return x > 0 ? x : -x;
}

int f(int i, int j, int r)
{
    return dx[r] * i + dy[r] * j;
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int kk = 1; kk <= k; kk++)
    {
        for (int r = 0; r < 4; r++)
        {
            int mx = -L;
            int mn = L;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (a[i][j] == kk)
                    {
                        mn = min(f(i, j, r), mn);
                        mx = max(f(i, j, r), mx);
                    }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (a[i][j] == kk && (f(i, j, r) == mn || f(i, j, r) == mx))
                        x[kk].push_back(i), y[kk].push_back(j);
        }
    }
    int res = 0;
    vector<int> ff(s);
    for (int i = 0; i < s; i++)
        cin >> ff[i];
    for (int i = 0; i < s - 1; i++)
        for (int x1 = 0; x1 < x[ff[i]].size(); x1++)
            for (int y1 = 0; y1 < y[ff[i + 1]].size(); y1++)
            {
                int ii = x[ff[i]][x1];
                int jj = y[ff[i]][x1];
                int iii = x[ff[i + 1]][y1];
                int jjj = y[ff[i + 1]][y1];
                res = max(res, absll(ii - iii) + absll(jj - jjj));
            }

    cout << res;

    return 0;
}