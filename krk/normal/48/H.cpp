#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int n, m;
int a, b, X;
char res[Maxn][Maxn];

void Black(int r, int c)
{
    r = 2 * r, c = 2 * c;
    res[r][c] = res[r + 1][c] = res[r][c + 1] = res[r + 1][c + 1] = '#';
}

void Diag(int r, int c, char typ, bool tp)
{
    r = 2 * r, c = 2 * c;
    if (typ == '\\') {
        res[r][c] = res[r + 1][c + 1] = '\\';
        if (tp) res[r][c + 1] = '#';
        else res[r + 1][c] = '#';
    } else if (typ == '/') {
        res[r][c + 1] = res[r + 1][c] = '/';
        if (tp) res[r][c] = '#';
        else res[r + 1][c + 1] = '#';
    }
}

void Kite(int r, int c)
{
    Diag(r, c, '/', false);
    Diag(r, c + 1, '\\', false);
    Diag(r + 1, c, '\\', true);
    Diag(r + 1, c + 1, '/', true);
}

void Left2(int r, int c)
{
    Diag(r, c, '\\', false);
    Diag(r + 1, c, '/', true);
}

void Right2(int r, int c)
{
    Diag(r, c, '/', false);
    Diag(r + 1, c, '\\', true);
}

void Bottom2(int r, int c)
{
    Diag(r, c, '/', false);
    Diag(r, c + 1, '\\', false);
}

void Print()
{
    for (int i = 0; i < 2 * n; i++) {
        res[i][2 * m] = '\0';
        printf("%s\n", res[i]);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &a, &b, &X);
    fill((char*)res, (char*)res + Maxn * Maxn, '.');
    int r = 0, c = 0;
    while (a >= m) {
        for (int i = 0; i < m; i++)
            Black(r, i);
        r++; a -= m;
    }
    while (a >= 1) {
        Black(r, c);
        c++; a--;
    }
    char fir = '/', sec = '\\';
    for (int j = c; j < m; j++) {
        Diag(r, j, fir, true);
        swap(fir, sec);
    }
    fir = '/', sec = '\\';
    for (int j = c - 1; j >= 0; j--) {
        Diag(r + 1, j, fir, true);
        swap(fir, sec);
    }
    X -= m;
    r++;
    if (c == 0) {
        for (int i = r; i + 1 < n; i += 2) {
            for (int j = 1; j + 1 < m; j += 2)
                if (X >= 4) { Kite(i, j); X -= 4; }
            if (X >= 2) { Left2(i, 0); X -= 2; }
            if (m % 2 == 0 && X >= 2) { Right2(i, m - 1); X -= 2; }
        }
        for (int j = 0; j + 1 < m; j += 2)
            if (X >= 2) { Bottom2(n - 1, j); X -= 2; }
        if (X >= 1) Diag(n - 1, m - 1, '/', false);
        Print();
        return 0;
    }
    for (int i = r; i + 1 < n; i += 2) {
        for (int j = c; j + 1 < m; j += 2)
            if (X >= 4) { Kite(i, j); X -= 4; }
        if ((m - c) % 2 != 0 && X >= 2) { Right2(i, m - 1); X -= 2; }
    }
    for (int i = r + 1; i + 1 < n; i += 2) {
        for (int j = c - 2; j >= 0; j -= 2)
            if (X >= 4) { Kite(i, j); X -= 4; }
        if (c % 2 != 0 && X >= 2) { Left2(i, 0); X -= 2; }
    }
    if ((n - r) % 2 != 0) {
        for (int j = c; j + 1 < m; j += 2)
            if (X >= 2) { Bottom2(n - 1, j); X -= 2; }
        if (X >= 1) Diag(n - 1, m - 1, '/', false);
    } else {
        for (int j = c - 2; j >= 0; j -= 2)
            if (X >= 2) { Bottom2(n - 1, j); X -= 2; }
        if (X >= 1) Diag(n - 1, 0, '\\', false);
    }
    Print();
    return 0;
}