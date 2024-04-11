#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const string lets = "AGCT";

int n, m;
string B[Maxn];
char tmp[Maxn];
string R[Maxn];
int best = Maxn;
char ba, bb, bc, bd;
bool column;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int checkCol(int c, char a, char b)
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += B[i][c] != a;
        swap(a, b);
    }
    return res;
}

int checkCols(char a, char b, char c, char d)
{
    int res = 0;
    for (int j = 0; j < m; j++) {
        res += min(checkCol(j, a, b), checkCol(j, b, a));
        swap(a, c); swap(b, d);
    }
    return res;
}

void writeCol(int c, char a, char b)
{
    for (int i = 0; i < n; i++) {
        R[i][c] = a;
        swap(a, b);
    }
}

void writeCols(char a, char b, char c, char d)
{
    for (int j = 0; j < m; j++) {
        if (checkCol(j, a, b) <= checkCol(j, b, a))
            writeCol(j, a, b);
        else writeCol(j, b, a);
        swap(a, c); swap(b, d);
    }
}

int checkRow(int r, char a, char b)
{
    int res = 0;
    for (int j = 0; j < m; j++) {
        res += B[r][j] != a;
        swap(a, b);
    }
    return res;
}

int checkRows(char a, char b, char c, char d)
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += min(checkRow(i, a, b), checkRow(i, b, a));
        swap(a, c); swap(b, d);
    }
    return res;
}

void writeRow(int r, char a, char b)
{
    for (int j = 0; j < m; j++) {
        R[r][j] = a;
        swap(a, b);
    }
}

void writeRows(char a, char b, char c, char d)
{
    for (int i = 0; i < n; i++) {
        if (checkRow(i, a, b) <= checkRow(i, b, a))
            writeRow(i, a, b);
        else writeRow(i, b, a);
        swap(a, c); swap(b, d);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        Read(B[i]);
        R[i].resize(m);
    }
    for (int i = 0; i < lets.length(); i++)
        for (int j = i + 1; j < lets.length(); j++) {
            int rem[2];
            int rlen = 0;
            for (int l = 0; l < lets.length(); l++) if (l != i && l != j)
                rem[rlen++] = l;
            char a = lets[i], b = lets[j];
            char c = lets[rem[0]], d = lets[rem[1]];
            int cand = checkCols(a, b, c, d);
            if (cand < best) {
                best = cand;
                ba = a; bb = b; bc = c; bd = d;
                column = true;
            }
            cand = checkRows(a, b, c, d);
            if (cand < best) {
                best = cand;
                ba = a; bb = b; bc = c; bd = d;
                column = false;
            }
        }
    if (column) writeCols(ba, bb, bc, bd);
    else writeRows(ba, bb, bc, bd);
    for (int i = 0; i < n; i++)
        printf("%s\n", R[i].c_str());
    return 0;
}