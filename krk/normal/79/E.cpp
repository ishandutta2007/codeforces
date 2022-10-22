#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxd = 4;

int n;
ll t;
int a, b, c;
ll X[Maxd], Y[Maxd];
ll has[Maxd];
ll lft[Maxd];
char str[2 * Maxn];
int slen;

ll Sum(int x, int y) { return ll(x + y) * (y - x + 1) / 2; }

ll quickRight(int x, int y, int tox, int cx, int cy)
{
    ll res = ll(tox - x) * abs(y - cy);
    if (cx <= x) res += Sum(x - cx + 1, tox - cx);
    else if (cx < tox) res += Sum(0, cx - x - 1) + Sum(0, tox - cx);
    else res += Sum(cx - tox, cx - x - 1);
    return res;
}

ll quickUp(int x, int y, int toy, int cx, int cy)
{
    ll res = ll(toy - y) * abs(x - cx);
    if (cy <= y) res += Sum(y - cy + 1, toy - cy);
    else if (cy < toy) res += Sum(0, cy - y - 1) + Sum(0, toy - cy);
    else res += Sum(cy - toy, cy - y - 1);
    return res;
}

ll quickRightUp(int x, int y, int tox, int toy, int cx, int cy)
{
    return quickRight(x, y, tox, cx, cy) + quickUp(tox, y, toy, cx, cy);
}

ll quickUpRight(int x, int y, int tox, int toy, int cx, int cy)
{
    return quickUp(x, y, toy, cx, cy) + quickRight(x, toy, tox, cx, cy);
}

bool Detected()
{
    for (int i = 0; i < Maxd; i++)
        if (lft[i] < 0) return true;
    return false;
}

bool Solve(int x, int y)
{
    for (int i = 0; i < Maxd; i++)
        lft[i] = has[i];
    if (y >= Y[0])
        for (int i = 0; i < Maxd; i++)
            lft[i] -= quickRightUp(x, y, n, n, X[i], Y[i]);
    else if (x >= X[1])
        for (int i = 0; i < Maxd; i++)
            lft[i] -= quickUpRight(x, y, n, n, X[i], Y[i]);
    else {
        if (x < X[0]) {
            for (int i = 0; i < Maxd; i++)
                lft[i] -= quickRight(x, y, X[0], X[i], Y[i]);
            x = X[0];
        }
        if (y < Y[2]) {
            for (int i = 0; i < Maxd; i++)
                lft[i] -= quickUp(x, y, Y[2], X[i], Y[i]);
            y = Y[2];
        }
        lft[0] -= quickUpRight(x, y, X[1], Y[1], X[0], Y[0]);
        lft[3] -= quickRightUp(x, y, X[1], Y[1], X[3], Y[3]);
        if (Detected()) return false;
        ll rem = quickRightUp(x, y, X[1], Y[1], X[0], Y[0]) - quickUpRight(x, y, X[1], Y[1], X[0], Y[0]);
        ll tk = min(rem, abs(lft[0] - lft[3]));
        if (lft[0] >= lft[3]) lft[0] -= tk;
        else lft[3] -= tk;
        rem -= tk;
        lft[0] -= rem / 2;
        lft[3] -= (rem + 1) / 2;
        lft[1] -= quickUpRight(x, y, X[1], Y[1], X[1], Y[1]);
        lft[2] -= quickUpRight(x, y, X[1], Y[1], X[2], Y[2]);
        for (int i = 0; i < Maxd; i++)
            lft[i] -= quickUpRight(X[1], Y[1], n, n, X[i], Y[i]);
    }       
    return !Detected();
}

bool canMoveRight(int &x, int y)
{
    if (x >= n) return false;
    x++;
    for (int i = 0; i < Maxd; i++)
        has[i] -= (abs(x - X[i]) + abs(y - Y[i]));
    if (Solve(x, y)) return true;
    for (int i = 0; i < Maxd; i++)
        has[i] += abs(x - X[i]) + abs(y - Y[i]);
    x--;
    return false;
}

void moveUp(int x, int &y)
{
    y++;
    for (int i = 0; i < Maxd; i++)
        has[i] -= (abs(x - X[i]) + abs(y - Y[i]));
}

int main()
{
    scanf("%d %I64d %d %d %d", &n, &t, &a, &b, &c);
    fill(has, has + Maxd, t);
    X[0] = X[2] = a;
    X[1] = X[3] = a + c - 1;
    Y[0] = Y[1] = b + c - 1;
    Y[2] = Y[3] = b;
    int x = 1, y = 1;
    if (!Solve(x, y)) {
        printf("Impossible\n");
        return 0;
    }
    while (x != n || y != n)
        if (canMoveRight(x, y)) str[slen++] = 'R';
        else {
            moveUp(x, y);
            str[slen++] = 'U';
        }
    str[slen] = '\0';
    printf("%s\n", str);
    return 0;
}