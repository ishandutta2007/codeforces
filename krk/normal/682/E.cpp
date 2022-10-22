#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> ldld;
typedef pair <ldld, int> ldldi;

const int Maxn = 5005;

int n;
ll S;
int X[Maxn], Y[Maxn];
vector <ldldi> seq;
vector <int> hull;
ld res = 0;
int ba, bb, bc;

ld Len(int a, int b)
{
    return sqrt(ld(X[a] - X[b]) * (X[a] - X[b]) + ld(Y[a] - Y[b]) * (Y[a] - Y[b]));
}

ll Cross(int a, int b, int c)
{
    ll ax = X[b] - X[a], ay = Y[b] - Y[a];
    ll bx = X[c] - X[a], by = Y[c] - Y[a];
    return ax * by - ay * bx;
}

int getNode(int st, int offset)
{
    return hull[(st + offset) % hull.size()];
}

int main()
{
    scanf("%d %I64d", &n, &S);
    int mn = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        if (X[i] < X[mn] || X[i] == X[mn] && Y[i] < Y[mn])
            mn = i;
    }
    for (int i = 0; i < n; i++) if (i != mn) {
        ld ang = atan2(ld(Y[i] - Y[mn]), ld(X[i] - X[mn]));
        ld len = Len(i, mn);
        seq.push_back(ldldi(ldld(ang, len), i));
    }
    sort(seq.begin(), seq.end());
    hull.push_back(mn);
    for (int i = 0; i < seq.size(); i++) {
        while (hull.size() >= 2 && Cross(hull[int(hull.size()) - 2], seq[i].second, hull.back()) >= 0)
            hull.pop_back();
        hull.push_back(seq[i].second);
    }
    while (hull.size() >= 3 && Cross(hull[int(hull.size()) - 2], hull[0], hull.back()) >= 0)
        hull.pop_back();
    for (int i = 0; i < hull.size(); i++) {
        int pnt = 0;
        for (int j = 1; j < hull.size(); j++) {
            pnt = max(pnt, j + 1);
            while (pnt + 1 < hull.size() && Cross(getNode(i, 0), getNode(i, j), getNode(i, pnt + 1)) >= Cross(getNode(i, 0), getNode(i, j), getNode(i, pnt)))
                pnt++;
            ld cand = Cross(getNode(i, 0), getNode(i, j), getNode(i, pnt));
            //printf("best (%d, %d) (%d, %d) (%d, %d) = %.5f\n", X[getNode(i, 0)], Y[getNode(i, 0)], X[getNode(i, j)], Y[getNode(i, j)], X[getNode(i, pnt)], Y[getNode(i, pnt)], double(cand));
            if (cand > res) {
                res = cand;
                ba = getNode(i, 0);
                bb = getNode(i, j);
                bc = getNode(i, pnt);
            }
        }
    }
    printf("%d %d\n", X[ba] + X[bb] - X[bc], Y[ba] + Y[bb] - Y[bc]);
    printf("%d %d\n", X[ba] + X[bc] - X[bb], Y[ba] + Y[bc] - Y[bb]);
    printf("%d %d\n", X[bb] + X[bc] - X[ba], Y[bb] + Y[bc] - Y[ba]);
    return 0;
}