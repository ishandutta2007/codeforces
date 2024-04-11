#include <bits/stdc++.h>

using namespace std;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int N = 1e6 + 5;

int t, kol[N];
vector<int> a;
vector<vector<int> > mat;

bool is(int x, int y, int n, int m) {
    return (x > 0 && y > 0 && x <= n && y <= m && mat[x][y] == -1);
}

void check(int n, int m) {
    int x = 1000000000;
    for (int i = 0; i < a.size(); i++)
        kol[a[i]] = 0;
    for (int i = 0; i < a.size(); i++)
        kol[a[i]]++;
    for (int i = 1; i <= n; i++)
        if (kol[i] < 4*i)
        {
            x = i;
            break;
        }
    if (x == 1000000000)
        return;
    int b = -1;
    for (int i = 0; i < a.size(); i++)
        b = max(b, a[i]);
    int y = n + m - x - b;
    mat.resize(n + 1);
    //cout << mat.size() << ' ' << n << ' ' << mat[0].size() << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        mat[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
            mat[i][j] = -1;
    }
    if (y > m)
        return;
    queue<pair<int, int> > q;
    q.push({x, y});
    mat[x][y] = 0;
    kol[0]--;

   /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << ' ' ;
        cout << endl;
    }
    cout << endl;
    *///cout << n << ' '  << m << ' ' << x << ' ' << y  << endl;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
            if (is(x + dx[d], y + dy[d], n, m))
            {
                mat[x + dx[d]][y + dy[d]] = mat[x][y] + 1;
                kol[mat[x][y] + 1]--;
                q.push({x + dx[d], y + dy[d]});
            }
    }
   /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << ' ' ;
        cout << endl;
    }
    cout << endl;
    */for (int i = 0; i < a.size(); i++)
        if (kol[a[i]] != 0)
            return;
    cout << n << ' ' << m << "\n" << x << ' ' << y;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    a.resize(t);
    for (int i = 0; i < t; i++)
        cin >> a[i];
    for (int i = 1; i*i <= t; i++)
        if (t % i == 0)
        {
            check(i, t / i);
            check(t / i, i);
        }
    cout << -1;
    return 0;
}