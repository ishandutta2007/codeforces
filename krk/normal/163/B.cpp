#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <int, int> ii;

const ld eps = 1e-12;

int n, k, h;
vector <ii> m;
vector <int> v;
ld l, r = 1000000000.0L;
vector <int> res;

bool Enough(ld lim)
{
    int need = k;
    for (int i = n - 1; i >= 0 && need > 0; i--)
        if (lim + eps >= ld(need * h) / ld(v[m[i].second])) need--;
    return !need;
}

void Collect(ld lim)
{
    int need = k;
    for (int i = n - 1; i >= 0 && need > 0; i--)
        if (lim + eps >= ld(need * h) / ld(v[m[i].second])) {
            res.push_back(m[i].second + 1); need--;
        }
}

bool Less(const ii &a, const ii &b)
{
    if (a.first != b.first) return a.first < b.first;
    return v[a.second] < v[b.second];
}

int main()
{
    scanf("%d %d %d", &n, &k, &h);
    m.resize(n); v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i].first);
        m[i].second = i;
    }
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(m.begin(), m.end(), Less);
    for (int i = 0; i < 100; i++) {
        ld mid = (l + r) / 2.0L;
        if (Enough(mid)) r = mid;
        else l = mid;
    }
    Collect(r);
    for (int i = res.size() - 1; i >= 0; i--) printf("%d%c", res[i], i > 0? ' ': '\n');
    return 0;
}