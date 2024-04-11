#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const int Inf = 800000005;
const int Maxn = 100005;

int n;
int ox[Maxn], oy[Maxn];
pair <int, int> p[Maxn];
int lft;
set <pair <int, int> > S;
int res;
pair <int, int> a, b;

int Sqrt(int x)
{
    return int(sqrt(double(x)) + 1e-6);
}

int getTrans(int x1, int x2, int y1, int y2)
{
    return 1 + 2 * (y1 != y2) + (x1 != x2);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ox[i] >> oy[i];
        p[i] = make_pair(abs(ox[i]), abs(oy[i]));
    }
    sort(p, p + n);
    res = Inf;
    for (int i = 0; i < n; i++) {
        while ((p[i].first - p[lft].first) * (p[i].first - p[lft].first) > res) {
              S.erase(make_pair(p[lft].second, p[lft].first));
              lft++;
        }
        set <pair <int, int> >::iterator it1, it2;
        it1 = S.lower_bound(make_pair(p[i].second - Sqrt(res), 0));
        it2 = S.upper_bound(make_pair(p[i].second + Sqrt(res), p[i].first));
        for (set <pair <int, int> >::iterator it = it1; it != it2; it++) {
            int cand = (p[i].first - it->second) * (p[i].first - it->second) +
                       (p[i].second - it->first) * (p[i].second - it->first);
            if (cand < res) {
                     res = cand;
                     a = p[i];
                     b = make_pair(it->second, it->first);
            }
        }
        S.insert(make_pair(p[i].second, p[i].first));
    }
    int inda = 0;
    while (a.first != abs(ox[inda]) || a.second != abs(oy[inda])) inda++;
    int indb = 0;
    while (inda == indb || b.first != abs(ox[indb]) || b.second != abs(oy[indb])) indb++;
    cout << inda + 1 << " " << getTrans(ox[inda], a.first, oy[inda], a.second) << " "
         << indb + 1 << " " << getTrans(ox[indb], -b.first, oy[indb], -b.second) << endl;
    return 0;
}