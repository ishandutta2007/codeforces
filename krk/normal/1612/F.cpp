#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 200005;

int n, m;
int q;
set <ii> S;
int cur, bestA[2][Maxn], bestB[2][Maxn];
int A[Maxn], B[Maxn];
int res = Inf;

int getPower(const ii &p)
{
    return p.first + p.second + S.count(p);
}

void Process(int a, int b, int t)
{
    int pw = getPower(ii(a, b));
    if (pw >= n) A[b] = min(A[b], t + 1);
    else {
        bestA[!cur][pw] = max(bestA[!cur][pw], b);
        bestB[!cur][b] = max(bestB[!cur][b], pw);
    }
    if (pw >= m) B[a] = min(B[a], t + 1);
    else {
        bestA[!cur][a] = max(bestA[!cur][a], pw);
        bestB[!cur][pw] = max(bestB[!cur][pw], a);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d", &q);
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        S.insert(ii(a, b));
    }
    fill(A, A + Maxn, Inf);
    fill(B, B + Maxn, Inf);
    bestA[cur][1] = max(bestA[cur][1], 1);
    bestB[cur][1] = max(bestB[cur][1], 1);
    for (int t = 0; t < 50; t++) {
        for (int a = 1; a < n; a++) if (bestA[cur][a])
            Process(a, bestA[cur][a], t);
        for (int b = 1; b < n; b++) if (bestB[cur][b])
            Process(bestB[cur][b], b, t);
        cur = !cur;
    }
    for (int i = 1; i < m; i++) {
        int pw = min(m, getPower(ii(n, i)));
        A[pw] = min(A[pw], A[i] + 1);
    }
    for (int i = 1; i < n; i++) {
        int pw = min(n, getPower(ii(i, m)));
        B[pw] = min(B[pw], B[i] + 1);
    }
    cout << min(A[m], B[n]) << endl;
    return 0;
}