#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

ll res;
int n, m, q;
bool B[Maxn][Maxn];
int dp[Maxn][Maxn][2];

int Get(int r, int c) { return max(dp[r][c][0] + dp[r][c][1] - 1, 0); }

void Recompute(int r, int c)
{
    if (B[r][c]) dp[r][c][0] = dp[r][c][1] = 0;
    else {
        dp[r][c][0] = dp[r][c + 1][1] + 1;
        dp[r][c][1] = dp[r + 1][c][0] + 1;
    }
}

void Change(int r, int c)
{
    res -= Get(r, c);
    Recompute(r, c);
    res += Get(r, c);
}

bool Inside(int r, int c)
{
    return r >= 0 && c >= 0;
}

void Move(int &a, int &b)
{
    a--; b--;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            Recompute(i, j);
            res += Get(i, j);
        }
    while (q--) {
        int r, c; scanf("%d %d", &r, &c);
        r--; c--;
        B[r][c] = !B[r][c];
        Change(r, c);
        int ar = r, ac = c - 1;
        int br = r - 1, bc = c;
        int cr = r - 1, cc = c - 1;
        while (Inside(ar, ac) || Inside(br, bc) || Inside(cr, cc)) {
            if (Inside(ar, ac)) Change(ar, ac);
            if (Inside(br, bc)) Change(br, bc);
            if (Inside(cr, cc)) Change(cr, cc);
            Move(ar, ac);
            Move(br, bc);
            Move(cr, cc);
        }
        printf("%I64d\n", res);
    }
    return 0;
}