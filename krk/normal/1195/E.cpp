#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 3005;

int n, m, a, b;
int g, x, y, z;
int B[Maxn][Maxn];
int my[Maxn][Maxn];
deque <ii> M;
ll res;

void Add(const ii &p)
{
    while (!M.empty() && M.back().first >= p.first) M.pop_back();
    M.push_back(p);
}

void Fix(int ind)
{
    while (M.front().second <= ind) M.pop_front();
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &a, &b);
    scanf("%d %d %d %d", &g, &x, &y, &z);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            B[i][j] = g;
            g = (ll(g) * x + ll(y)) % z;
        }
    for (int j = 0; j < m; j++) {
        M.clear();
        for (int i = 0; i < a - 1; i++)
            Add(ii(B[i][j], i));
        for (int i = a - 1; i < n; i++) {
            Add(ii(B[i][j], i));
            Fix(i - a);
            my[i][j] = M.front().first;
        }
    }
    for (int i = a - 1; i < n; i++) {
        M.clear();
        for (int j = 0; j < b - 1; j++)
            Add(ii(my[i][j], j));
        for (int j = b - 1; j < m; j++) {
            Add(ii(my[i][j], j));
            Fix(j - b);
            res += M.front().first;
        }
    }
    cout << res << endl;
    return 0;
}