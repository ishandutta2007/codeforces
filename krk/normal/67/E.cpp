#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 10005;

int n;
int X[Maxn], Y[Maxn];
vector <ii> seq;
int L, R;

ll Cross(const ii &a, const ii &b, const ii &c)
{
    int ax = b.first - a.first, ay = b.second - a.second;
    int bx = c.first - a.first, by = c.second - a.second;
    return ll(ax) * by - ll(ay) * bx;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    if (X[0] <= X[1])
        for (int i = X[0]; i <= X[1]; i++)
            seq.push_back(ii(i, Y[0]));
    else for (int i = X[0]; i >= X[1]; i--)
            seq.push_back(ii(i, Y[0]));
    L = 0, R = int(seq.size()) - 1;
    for (int i = 2; i < n; i++) {
        ii my = seq[0];
        for (int j = i + 1; j < n; j++)
            if (Cross(ii(X[i], Y[i]), ii(X[j], Y[j]), my) > 0) my = ii(X[j], Y[j]);
        int lef = L, rig = int(seq.size()) - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Cross(ii(X[i], Y[i]), seq[mid], my) >= 0) rig = mid - 1;
            else lef = mid + 1;
        }
        L = lef;
        my = seq.back();
        for (int j = i - 1; j > 1; j--)
            if (Cross(ii(X[i], Y[i]), ii(X[j], Y[j]), my) < 0) my = ii(X[j], Y[j]);
        lef = 0, rig = R;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Cross(ii(X[i], Y[i]), my, seq[mid]) >= 0) lef = mid + 1;
            else rig = mid - 1;
        }
        R = rig;
    }
    int res = max(0, R - L + 1);
    printf("%d\n", res);
    return 0;
}