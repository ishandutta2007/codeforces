#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, ans = 0;

struct SPoint
{
    long long x, y;
} a[N];
vector<SPoint> ve;

long long cross(SPoint &a, SPoint &b, SPoint &c)
{
    long long x1 = a.x - b.x, y1 = a.y - b.y;
    long long x2 = a.x - c.x, y2 = a.y - c.y;
    return x1 * y2 - x2 * y1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].y -= a[i].x * a[i].x;
    }
    sort(a + 1, a + n + 1, [](const SPoint &a, const SPoint &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    for (int i = 1; i <= n; i++)
    {
        while (ve.size() >= 2 && cross(ve[ve.size() - 2], ve[ve.size() - 1], a[i]) >= 0)
            ve.pop_back();
        ve.push_back(a[i]);
    }
    for (int i = 1; i < ve.size(); i++)
        if (ve[i].x != ve[i - 1].x)
            ans++;
    cout << ans;
}