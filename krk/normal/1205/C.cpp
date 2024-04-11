#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 52;

int n;
int B[Maxn][Maxn];
int spec;
vector <ii> seq;

int Ask(int x1, int y1, int x2, int y2)
{
    printf("? %d %d %d %d\n", x1, y1, x2, y2); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

bool Get()
{
    if (seq.size() >= 4) {
        if ((B[seq[0].first][seq[0].second] == B[seq[2].first][seq[2].second]) ==
            (B[seq[1].first][seq[1].second] == B[seq[3].first][seq[3].second])) {
            if (Ask(seq[0].first, seq[0].second, seq[3].first, seq[3].second))
                spec = (B[seq[0].first][seq[0].second] != B[seq[3].first][seq[3].second]);
            else spec = (B[seq[0].first][seq[0].second] == B[seq[3].first][seq[3].second]);
            return true;
        }
        return false;
    }
    ii p = seq.back();
    if (p.first < n) {
        p.first++;
        seq.push_back(p);
        if (Get()) return true;
        p.first--;
        seq.pop_back();
    }
    if (p.second < n) {
        p.second++;
        seq.push_back(p);
        if (Get()) return true;
        p.second--;
        seq.pop_back();
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = n; i > 0; i--)
        for (int j = n; j > 0; j--) if ((i + j) % 2 == 0)
            if (i == n && j == n) continue;
            else if (j + 2 <= n) B[i][j] = (B[i][j + 2] ^ (Ask(i, j, i, j + 2)? 0: 1));
            else if (j + 1 <= n) B[i][j] = (B[i + 1][j + 1] ^ (Ask(i, j, i + 1, j + 1)? 0: 1));
            else B[i][j] = (B[i + 2][j] ^ (Ask(i, j, i + 2, j)? 0: 1));
    for (int j = n - 1; j > 0; j--)
        for (int i = n; i > 0; i--) if ((i + j) % 2 == 1)
            if (i == n && j == n - 1) continue;
            else if (i + 2 <= n) B[i][j] = (B[i + 2][j] ^ (Ask(i, j, i + 2, j)? 0: 1));
            else if (i + 1 <= n) B[i][j] = (B[i + 1][j + 1] ^ (Ask(i, j, i + 1, j + 1)? 0: 1));
            else B[i][j] = (B[i][j + 2] ^ (Ask(i, j, i, j + 2)? 0: 1));
    for (int i = n - 1; i > 0; i -= 2)
        B[i][n] = (B[i - 1][n - 1] ^ (Ask(i - 1, n - 1, i, n)? 0: 1));
    bool stp = false;
    for (int i = 1; i <= n && !stp; i++)
        for (int j = 1; j <= n && !stp; j++) {
            seq.push_back(ii(i, j));
            if (Get()) { stp = true; break; }
            seq.pop_back();
        }
    printf("!\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 1)
                B[i][j] ^= spec;
            printf("%d", B[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);
    return 0;
}