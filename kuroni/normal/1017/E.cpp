#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

struct SPoint
{
    int x, y;
};
vector<SPoint> a, b;

long long S(SPoint &a, SPoint &b, SPoint &c)
{
    return 1LL * (a.x - b.x) * (a.y + b.y)
         + 1LL * (b.x - c.x) * (b.y + c.y)
         + 1LL * (c.x - a.x) * (c.y + a.y);
}

bool eql(double a, double b)
{
    return abs(a - b) < 1E-6;
}

void construct(int n, vector<SPoint> &res)
{
    vector<SPoint> ve, hi, lo;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ve.push_back((SPoint){x, y});
    }
    sort(ve.begin(), ve.end(), [](const SPoint &a, const SPoint &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
    for (SPoint &v : ve)
    {
        while (hi.size() >= 2 && S(hi[hi.size() - 2], hi[hi.size() - 1], v) >= 0)
            hi.pop_back();
        hi.push_back(v);
        while (lo.size() >= 2 && S(lo[lo.size() - 2], lo[lo.size() - 1], v) <= 0)
            lo.pop_back();
        lo.push_back(v);
    }
    for (unsigned int i = 0; i < hi.size() - 1; i++)
        res.push_back(hi[i]);
    for (unsigned int i = lo.size() - 1; i > 0; i--)
        res.push_back(lo[i]);
}

void flatten(vector<SPoint> &a, vector<double> &res)
{
    int n = a.size();
    a.push_back(a[0]);
    a.push_back(a[1]);
    for (int i = 0; i < n; i++)
    {
        res.push_back(hypot(a[i].x - a[i + 1].x, a[i].y - a[i + 1].y));
        res.push_back(-hypot(a[i].x - a[i + 2].x, a[i].y - a[i + 2].y));
    }
}

bool compare(vector<SPoint> &a, vector<SPoint> &b)
{
    if (a.size() != b.size())
        return false;
    vector<double> x, y;
    flatten(a, x);
    flatten(b, y);
    for (unsigned int i = 0; i < y.size(); i++)
        x.push_back(x[i]);
    int kmp[N * 2], cur = 0;
    kmp[0] = 0;
    for (unsigned int i = 1; i < y.size(); i++)
    {
        kmp[i] = kmp[i - 1];
        while (kmp[i] != 0 && !eql(y[i], y[kmp[i]]))
            kmp[i] = kmp[kmp[i]];
        if (eql(y[i], y[kmp[i]]))
            kmp[i]++;
    }
    for (unsigned int i = 0; i < x.size(); i++)
    {
        while (cur != 0 && !eql(x[i], y[cur]))
            cur = kmp[cur];
        if (eql(x[i], y[cur]))
            cur++;
        if (cur == y.size())
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    construct(n, a);
    construct(m, b);
    printf("%s", compare(a, b) ? "YES" : "NO");
}