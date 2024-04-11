#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

char tmp[Maxn];
int T;
int n, m;
string B[Maxn];

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

bool Free(int r, int c) { return 0 <= r && r < n && 0 <= c && c < m && B[r][c] != '#'; }

bool Good(int r, int c) { return B[r][c] == '+' || B[r][c] == 'L'; }

bool Check(int r, int c)
{
    if (!Free(r, c) || Good(r, c)) return false;
    int fre = 0, bad = 0;
    for (int d = 0; d < Maxd; d++) {
        int nr = r + dy[d], nc = c + dx[d];
        if (!Free(nr, nc)) continue;
        fre++;
        if (!Good(nr, nc)) bad++;
    }
    if (!fre) return false;
    return bad <= 1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int r, c;
        for (int i = 0; i < n; i++)
            Read(B[i]);
        vector <ii> seq;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (B[i][j] == 'L')
                    seq.push_back(ii(i, j));
        for (int i = 0; i < seq.size(); i++) {
            ii v = seq[i];
            for (int j = 0; j < Maxd; j++) {
                ii u = ii(v.first + dy[j], v.second + dx[j]);
                if (Check(u.first, u.second)) {
                    B[u.first][u.second] = '+';
                    seq.push_back(u);
                }
            }
        }
        for (int i = 0; i < n; i++)
            printf("%s\n", B[i].c_str());
    }
    return 0;
}