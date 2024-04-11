#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 0, 1};
const int dx[Maxd] = {0, -1, 1, 0};

int n, m, k;
char B[Maxn][Maxn];
int R1[Maxn], R2[Maxn], C1[Maxn], C2[Maxn];
int seq[Maxn];
int slen;
ll res;
int tmp[Maxn], tlen;
bool bad[Maxn];
int f[Maxn];

void Fill(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] != '*') return;
    B[r][c] = '.';
    R1[slen] = min(R1[slen], r);
    R2[slen] = max(R2[slen], r);
    C1[slen] = min(C1[slen], c);
    C2[slen] = max(C2[slen], c);
    for (int i = 0; i < Maxd; i++)
        Fill(r + dy[i], c + dx[i]);
}

bool Less(const int &a, const int &b)
{
    return R2[a] < R2[b];
}

ll Solve(int a, int b)
{
    ll res = 0;
    tlen = 1;
    for (int i = 0; i < slen; i++) {
        int lef = max(a, C1[seq[i]]);
        int rig = min(b, C2[seq[i]]);
        if (lef > rig) continue;
        tmp[tlen] = seq[i];
        bad[tlen] = lef != C1[seq[i]] || rig != C2[seq[i]];
        tlen++;
    }
    f[tlen] = n;
    for (int i = tlen - 1; i > 0; i--)
        f[i] = min(f[i + 1], R1[tmp[i]]);
    for (int i = 1; i < tlen; i++) {
        int mn = Maxn;
        for (int j = 0; j < 3 && i + j < tlen && !bad[i + j]; j++) {
            mn = min(mn, R1[tmp[i + j]]);
            int L = i > 1? R2[tmp[i - 1]]: -1;
            if (L < mn && R2[tmp[i + j]] < f[i + j + 1])
                res += ll(mn - L) * (f[i + j + 1] - R2[tmp[i + j]]);
        }
    }
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] == '*') {
                R1[slen] = C1[slen] = Maxn;
                R2[slen] = C2[slen] = -Maxn;
                Fill(i, j);
                seq[slen] = slen;
                slen++;
            }
    sort(seq, seq + slen, Less);
    for (int a = 0; a < m; a++)
        for (int b = a; b < m; b++)
            res += Solve(a, b);
    cout << res << endl;
    return 0;
}