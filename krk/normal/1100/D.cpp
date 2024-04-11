#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000;
const int mid = 500;
const int Maxd = 666;
const int Maxp = 4;

int r, c;
int X[Maxd + 1], Y[Maxd + 1];
bool tk[Maxn][Maxn];
int DR[Maxp], DC[Maxp];

void realMove(int dr, int dc)
{
    r += dr; c += dc;
    printf("%d %d\n", r, c);
    fflush(stdout);
}

void Move(int dr, int dc)
{
    if (tk[r + dr][c + dc])
        realMove(dr, 0);
    else realMove(dr, dc);
}

bool getMove()
{
    int ind, x, y; scanf("%d %d %d", &ind, &x, &y);
    if (ind <= 0) return false;
    tk[X[ind]][Y[ind]] = false;
    X[ind] = x; Y[ind] = y;
    tk[X[ind]][Y[ind]] = true;
    return true;
}

int main()
{
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= Maxd; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        tk[X[i]][Y[i]] = true;
    }
    while (r != mid || c != mid) {
        int dr = 0, dc = 0;
        if (r < mid) dr = 1;
        else if (r > mid) dr = -1;
        if (c < mid) dc = 1;
        else if (c > mid) dc = -1;
        Move(dr, dc);
        if (!getMove()) return 0;
    }
    DR[0] = -1; DC[0] = 1;
    DR[1] = 1; DC[1] = 1;
    DR[2] = 1; DC[2] = -1;
    DR[3] = -1; DC[3] = -1;
    int has[Maxp] = {};
    for (int i = 1; i <= Maxd; i++)
        if (X[i] < mid)
            if (Y[i] < mid) has[0]++;
            else has[1]++;
        else if (Y[i] < mid) has[3]++;
             else has[2]++;
    int best = -1, bi, bj;
    for (int i = 0; i < Maxp; i++) {
        int ni = (i + 1) % Maxp;
        int ni2 = (i + 2) % Maxp;
        int cand = has[i] + has[ni] + has[ni2];
        if (cand > best) { best = cand; bi = DR[i]; bj = DC[i]; }
    }
    do Move(bi, bj);
    while (getMove());
    return 0;
}