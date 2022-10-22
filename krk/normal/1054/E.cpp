#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 305;
const int Maxm = 305;
const int Maxl = 100005;

char tmp[Maxl];
int n, m;
string A[Maxn][Maxm];
string B[Maxn][Maxm];
int pnt[Maxn][Maxm];
int zers[Maxm], ones[Maxm];
int nzers[Maxm];
vector <ii> res1, res2;

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

void Move(int r1, int c1, int r2, int c2)
{
    res1.push_back(ii(r1, c1));
    res2.push_back(ii(r2, c2));
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            Read(A[i][j]);
            for (int l = int(A[i][j].size()) - 1; l >= 0; l--) {
                char ch = A[i][j][l];
                if (ch == '0') {
                    int targ;
                    if (i != 1) targ = j;
                    else if (j == 1) targ = 2;
                    else targ = 1;
                    Move(i, j, 1, targ); zers[targ]++;
                } else {
                    int targ;
                    if (i != 2) targ = j;
                    else if (j == 1) targ = 2;
                    else targ = 1;
                    Move(i, j, 2, targ); ones[targ]++;
                }
            }
        }
    for (int j = 2; j <= m; j++) {
        while (zers[j] > 0) { Move(1, j, 1, 1); zers[j]--; }
        while (ones[j] > 0) { Move(2, j, 2, 1); ones[j]--; }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            Read(B[i][j]);
            pnt[i][j] = int(B[i][j].length()) - 1;
            if (i > 1)
                for (int l = 0; l < B[i][j].length(); l++)
                    if (B[i][j][l] == '0') nzers[j]++;
        }
    // 1st col
    while (pnt[1][1] >= 0) {
        char nd = B[1][1][pnt[1][1]--];
        if (nd == '0') { Move(1, 1, 1, 2); Move(1, 2, 1, 1); }
        else Move(2, 1, 1, 1);
    }
    while (pnt[2][1] >= 0) {
        char nd = B[2][1][pnt[2][1]--];
        if (nd == '0') Move(1, 1, 2, 1);
        else { Move(2, 1, 2, 2); Move(2, 2, 2, 1); }
    }
    for (int i = 3; i <= n; i++)
        while (pnt[i][1] >= 0) {
            char nd = B[i][1][pnt[i][1]--];
            if (nd == '0') Move(1, 1, i, 1);
            else Move(2, 1, i, 1);
        }
    // 2nd+ cols
    for (int j = 2; j <= m; j++) {
        while (nzers[j]--) Move(1, 1, 1, j);
        while (pnt[1][j] >= 0) {
            char nd = B[1][j][pnt[1][j]--];
            if (nd == '0') Move(1, 1, 1, j);
            else { Move(2, 1, 2, j); Move(2, j, 1, j); }
        }
        for (int i = 3; i <= n; i++)
            while (pnt[i][j] >= 0) {
                char nd = B[i][j][pnt[i][j]--];
                if (nd == '0') Move(1, j, i, j);
                else { Move(2, 1, 2, j); Move(2, j, i, j); }
            }
        while (pnt[2][j] >= 0) {
            char nd = B[2][j][pnt[2][j]--];
            if (nd == '0') Move(1, j, 2, j);
            else Move(2, 1, 2, j);
        }
    }
    printf("%d\n", int(res1.size()));
    for (int i = 0; i < res1.size(); i++)
        printf("%d %d %d %d\n", res1[i].first, res1[i].second, res2[i].first, res2[i].second);
    return 0;
}