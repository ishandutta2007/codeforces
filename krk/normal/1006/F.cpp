#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 22;

map <ll, int> M[Maxn][Maxn];
int n, m;
ll k;
ll B[Maxn][Maxn];
int L, R;
ll res;

void Insert(map <ll, int> &M, ll key)
{
    map <ll, int>::iterator it = M.find(key);
    if (it == M.end()) M.insert(make_pair(key, 1));
    else it->second++;
}

int Get(map <ll, int> &M, ll key)
{
    map <ll, int>::iterator it = M.find(key);
    return it == M.end()? 0: it->second;
}

void Solve1(int r, int c, int s, ll cur)
{
    if (s == L) Insert(M[r][c], cur);
    else {
        if (r + 1 < n) Solve1(r + 1, c, s + 1, (cur ^ B[r + 1][c]));
        if (c + 1 < m) Solve1(r, c + 1, s + 1, (cur ^ B[r][c + 1]));
    }
}

void Solve2(int r, int c, int s, ll cur)
{
    if (r > 0)
        if (s == R) res += Get(M[r - 1][c], (k ^ cur));
        else Solve2(r - 1, c, s + 1, (cur ^ B[r - 1][c]));
    if (c > 0)
        if (s == R) res += Get(M[r][c - 1], (k ^ cur));
        else Solve2(r, c - 1, s + 1, (cur ^ B[r][c - 1]));
}

int main()
{
    scanf("%d %d %I64d", &n, &m, &k);
    ll all = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%I64d", &B[i][j]);
            all ^= B[i][j];
        }
    if (n == 1) printf("%d\n", all == k? 1: 0);
    else {
        L = (n + m - 1) / 2;
        R = (n + m - 1) - L;
        Solve1(0, 0, 1, B[0][0]);
        Solve2(n - 1, m - 1, 1, B[n - 1][m - 1]);
        cout << res << endl;
    }
    return 0;
}