#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;

const int Maxn = 105;
const ld eps = 1e-14l;

int n;
int X[Maxn], Y[Maxn];
map <ii, int> M;
ld res;

ld Len(ld x, ld y) { return sqrt(x * x + y * y); }

ll sqLen(int x, int y) { return ll(x) * x + ll(y) * y; }

ll Dot(int a, int b, int c)
{
    int ax = X[b] - X[a], ay = Y[b] - Y[a];
    int bx = X[c] - X[a], by = Y[c] - Y[a];
    return ll(ax) * bx + ll(ay) * by;
}

void Check(ld x, ld y, ld r, const vector <int> &av)
{
    for (int i = 0; i < n; i++) if (find(av.begin(), av.end(), i) == av.end()) {
        ld dist = Len(x - X[i], y - Y[i]);
        if (dist + eps < r) return;
    }
    res = max(res, r);
}

void getPerp(int a, int b, ld &A, ld &B, ld &C)
{
    B = Y[a] - Y[b], A = X[a] - X[b];
    ld x = (X[a] + X[b]) / 2.0l;
    ld y = (Y[a] + Y[b]) / 2.0l;
    C = A * x + B * y;
}

void Triangle(int a, int b, int c)
{
    ld A1, B1, C1; getPerp(a, b, A1, B1, C1);
    ld A2, B2, C2; getPerp(b, c, A2, B2, C2);
    ld det = A1 * B2 - A2 * B1;
    ld x = (B2 * C1 - B1 * C2) / det;
    ld y = (A1 * C2 - A2 * C1) / det;
    ld r = Len(x - X[a], y - Y[a]);
    Check(x, y, r, {a, b, c});
}

void Square(int a, int b, int c)
{
  /*  if (sqLen(X[a] - X[b], Y[a] - Y[b]) != sqLen(X[a] - X[c], Y[a] - Y[c]))
        return;*/
    int othX = X[b] + X[c] - X[a], othY = Y[b] + Y[c] - Y[a];
    auto it = M.find(ii(othX, othY));
    if (it == M.end()) return;
    int d = it->second;
    ld x = (X[b] + X[c]) / 2.0l;
    ld y = (Y[b] + Y[c]) / 2.0l;
    ld r = Len(x - X[a], y - Y[a]);
    Check(x, y, r, {a, b, c, d});
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        M[ii(X[i], Y[i])] = i;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++) {
                if (Dot(i, j, k) > 0 && Dot(j, i, k) > 0 && Dot(k, i, j) > 0)
                    Triangle(i, j, k);
                if (Dot(i, j, k) == 0)
                    Square(i, j, k);
                else if (Dot(j, i, k) == 0)
                    Square(j, i, k);
                else if (Dot(k, i, j) == 0)
                    Square(k, i, j);
            }
    if (res == 0) cout << "-1\n";
    else cout << fixed << setprecision(15) << res << endl;
    return 0;
}