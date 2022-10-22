#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 3;

struct cond {
    bool checkX, lessX;
    int valX;
    bool checkY, lessY;
    int valY;
    cond(): checkX(false), checkY(false) {}
};

int n;
vector <ii> byX[Maxd], byY[Maxd];

bool LessY(const ii &a, const ii &b)
{
    return a.second < b.second;
}

bool Check(const ii &p, const cond &c)
{
    if (c.checkX && (c.lessX && p.first >= c.valX || !c.lessX && p.first <= c.valX)) return false;
    if (c.checkY && (c.lessY && p.second >= c.valY || !c.lessY && p.second <= c.valY)) return false;
    return true;
}

bool Solve2(const vector <int> &seq, int hm, const cond &c)
{
    int v = seq[2];
    int lft = hm;
    for (int i = 0; i < byX[v].size(); i++) {
        auto p = byX[v][i];
        if (Check(p, c))
            if (--lft == 0) return true;
    }
    return false;
}

bool Solve1(const vector <int> &seq, int hm, const cond &c)
{
    int v = seq[1];
    if (!c.checkX || !c.lessX) {
        int lft = hm;
        for (int i = 0; i < byX[v].size(); i++) {
            auto p = byX[v][i];
            if (Check(p, c))
                if (--lft == 0) {
                    cond nc = c;
                    nc.checkX = true;
                    nc.lessX = false;
                    nc.valX = p.first;
                    if (Solve2(seq, hm, nc))
                        return true;
                    break;
                }
        }
    }
    if (!c.checkY || !c.lessY) {
        int lft = hm;
        for (int i = 0; i < byY[v].size(); i++) {
            auto p = byY[v][i];
            if (Check(p, c))
                if (--lft == 0) {
                    cond nc = c;
                    nc.checkY = true;
                    nc.lessY = false;
                    nc.valY = p.second;
                    if (Solve2(seq, hm, nc))
                        return true;
                    break;
                }
        }
    }
    return false;
}

bool Check(int k)
{
    vector <int> seq = {0, 1, 2};
    do {
        int v = seq[0];
        cond c;
        c.checkX = true;
        c.lessX = false;
        c.valX = byX[v][k - 1].first;
        if (Solve1(seq, k, c)) return true;
        c.lessX = true;
        c.valX = byX[v][n - k].first;
        if (Solve1(seq, k, c)) return true;
        c.checkX = false;
        c.checkY = true;
        c.lessY = false;
        c.valY = byY[v][k - 1].second;
        if (Solve1(seq, k, c)) return true;
        c.lessY = true;
        c.valY = byY[v][n - k].second;
        if (Solve1(seq, k, c)) return true;
    } while (next_permutation(seq.begin(), seq.end()));
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y, c; scanf("%d %d %d", &x, &y, &c); c--;
        byX[c].push_back(ii(x, y));
        byY[c].push_back(ii(x, y));
    }
    for (int i = 0; i < Maxd; i++) {
        sort(byX[i].begin(), byX[i].end());
        sort(byY[i].begin(), byY[i].end(), LessY);
    }
    n /= 3;
    int lef = 1, rig = n;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) lef = mid + 1;
        else rig = mid - 1;
    }
    printf("%d\n", 3 * rig);
    return 0;
}