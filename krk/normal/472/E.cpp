#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 32;

int n, m;
int A[Maxn][Maxn], B[Maxn][Maxn];
ii cur, nd;
vector <ii> res;

void Read(int C[][Maxn])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &C[i][j]);
}

bool sameTiles()
{
    multiset <int> sA, sB;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            sA.insert(A[i][j]);
            sB.insert(B[i][j]);
        }
    return sA == sB;
}

vector <int> collectExcept(int C[][Maxn], int r, int c)
{
    vector <int> res;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (i != r || j != c)
            res.push_back(C[i][j]);
    return res;
}

void Write(int r, int c)
{
    res.push_back(ii(r + 1, c + 1));
}

void writeAll()
{
    printf("%d\n", int(res.size()) - 1);
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
}

ii Find(int col, ii ign = ii(-1, -1))
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (ii(i, j) != ign)
            if (A[i][j] == col) return ii(i, j);
    assert(false);
    return ii(-1, -1);
}

void Move(int dr, int dc)
{
    ii ncur = ii(cur.first + dr, cur.second + dc);
    swap(A[cur.first][cur.second], A[ncur.first][ncur.second]);
    if (ncur == nd) nd = cur;
    Write(ncur.first, ncur.second);
    cur = ncur;
}

void Carry(int dr, int dc)
{
    ii old = cur;
    Move(nd.first - cur.first, nd.second - cur.second);
    Move(dr, dc);
    Move(old.first - cur.first, old.second - cur.second);
}

void Solve()
{
    cur = Find(B[0][0]);
    Write(cur.first, cur.second);
    while (cur.first + 1 < n) Move(1, 0);
    while (n > 2) {
        for (int j = m - 1; j >= 0; j--) {
            nd = Find(B[n - 1][j], cur);
            while (cur.first >= nd.first && cur.first > 0)
                Move(-1, 0);
            if (cur.first == nd.first) {
                while (cur.second - 1 > nd.second) Move(0, -1);
                while (cur.second + 1 < nd.second) Move(0, 1);
                Carry(1, 0);
            }
            while (cur.second > nd.second) Move(0, -1);
            while (cur.second < nd.second) Move(0, 1);
            while (nd.second > j) {
                Carry(0, -1);
                Move(0, -1);
            }
            while (nd.second < j) {
                Carry(0, 1);
                Move(0, 1);
            }
            if (nd.first != n - 1) {
                if (j > 0) Move(1, -1);
                else Move(1, 1);
                while (true) {
                    Carry(1, 0);
                    if (nd.first == n - 1) break;
                    Move(1, 0);
                }
            }
        }
        n--;
    }
    while (cur.second + 1 < m) Move(0, 1);
    while (m > 2) {
        for (int i = 1; i >= 0; i--) {
            nd = Find(B[i][m - 1], cur);
            while (cur.second >= nd.second && cur.second > 0)
                Move(0, -1);
            if (cur.second == nd.second)
                Carry(0, 1);
            while (cur.first > nd.first) Move(-1, 0);
            while (cur.first < nd.first) Move(1, 0);
            while (nd.first > i) {
                Carry(-1, 0);
                Move(-1, 0);
            }
            while (nd.first < i) {
                Carry(1, 0);
                Move(1, 0);
            }
            if (nd.second != m - 1) {
                if (i > 0) Move(-1, 1);
                else Move(1, 1);
                while (true) {
                    Carry(0, 1);
                    if (nd.second == m - 1) break;
                    Move(0, 1);
                }
            }
        }
        m--;
    }
    if (cur != ii(1, 1))
        Move(1 - cur.first, 1 - cur.second);
    if (A[0][0] == B[1][1]) Move(-1, -1);
    else if (A[0][1] == B[1][1]) Move(-1, 0);
    else if (A[1][0] == B[1][1]) Move(0, -1);
    if (cur != ii(0, 0))
        Move(-cur.first, -cur.second);
    if (A[0][1] != B[0][1]) {
        nd = ii(0, 1);
        Carry(1, -1);
    }
    writeAll();
}

int main()
{
    scanf("%d %d", &n, &m);
    Read(A);
    Read(B);
    if (!sameTiles()) { printf("-1\n"); return 0; }
    if (n == 1 || m == 1) {
        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < m; j1++)
                for (int i2 = 0; i2 < n; i2++)
                    for (int j2 = 0; j2 < m; j2++) if (A[i1][j1] == B[i2][j2])
                        if (collectExcept(A, i1, j1) == collectExcept(B, i2, j2)) {
                            Write(i1, j1);
                            do {
                                if (i1 < i2) i1++;
                                else if (i1 > i2) i1--;
                                else if (j1 < j2) j1++;
                                else if (j1 > j2) j1--;
                                Write(i1, j1);
                            } while (i1 != i2 || j1 != j2);
                            writeAll();
                            return 0;
                        }
        printf("-1\n");
        return 0;
    }
    Solve();
    return 0;
}