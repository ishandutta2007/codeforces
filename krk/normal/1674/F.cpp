#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, m, q;
char B[Maxn][Maxn];
map <int, int> M;
int cnt;

int getId(int r, int c) { return (c - 1) * n + r; }

void Add(int id, int delt)
{
    auto it = M.find(id);
    if (it == M.end()) M.insert(make_pair(id, delt));
    else {
        it->second += delt;
        if (it->second == 0) M.erase(it);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", B[i] + 1);
        for (int j = 1; j <= m; j++)
            if (B[i][j] == '*') {
                Add(getId(i, j), 1);
                cnt++;
            }
    }
    for (int j = 1; j <= cnt; j++)
        Add(j, -1);
    while (q--) {
        int r, c; scanf("%d %d", &r, &c);
        if (B[r][c] == '*') {
            B[r][c] = '.';
            Add(getId(r, c), -1);
            Add(cnt, 1);
            cnt--;
        } else {
            B[r][c] = '*';
            Add(getId(r, c), 1);
            cnt++;
            Add(cnt, -1);
        }
        printf("%d\n", int(M.size()) / 2);
    }
    return 0;
}