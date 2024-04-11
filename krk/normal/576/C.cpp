#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;

int n;
int x[Maxn], y[Maxn];
int nxt[Maxn];

ii Get(const vector <int> &seq)
{
    if (seq.empty()) return ii(-1, -1);
    if (seq.size() <= 1) return ii(seq[0], seq[0]);
    int X1 = Maxn, X2 = -Maxn, Y1 = Maxn, Y2 = -Maxn;
    for (int i = 0; i < seq.size(); i++) {
        X1 = min(X1, x[seq[i]]); X2 = max(X2, x[seq[i]]);
        Y1 = min(Y1, y[seq[i]]); Y2 = max(Y2, y[seq[i]]);
    }
    int mX = X1 + X2 >> 1, mY = Y1 + Y2 >> 1;
    vector <int> d1, d2, d3, d4;
    for (int i = 0; i < seq.size(); i++)
        if (x[seq[i]] <= mX)
            if (y[seq[i]] <= mY) d1.push_back(seq[i]);
            else d2.push_back(seq[i]);
        else if (y[seq[i]] <= mY) d4.push_back(seq[i]);
             else d3.push_back(seq[i]);
    ii cur[4];
    cur[0] = Get(d1);
    cur[1] = Get(d2);
    cur[2] = Get(d3);
    cur[3] = Get(d4);
    int i = 0;
    while (cur[i] == ii(-1, -1)) i++;
    int fir = cur[i].first, lst = cur[i].second;
    for (int j = i + 1; j < 4; j++) if (cur[j] != ii(-1, -1)) {
        nxt[lst] = cur[j].first; lst = cur[j].second;
    }
    return ii(fir, lst);
}

int main()
{
    scanf("%d", &n);
    vector <int> all;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        all.push_back(i);
    }
    ii res = Get(all);
    int v = res.first;
    for (int i = 0; i < n; i++) {
        printf("%d%c", v, i + 1 < n? ' ': '\n');
        v = nxt[v];
    }
    return 0;
}