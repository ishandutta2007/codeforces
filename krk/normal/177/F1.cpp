#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int Maxn = 25;

int n, k, t;
vector <int> w[Maxn], r[Maxn];
bool taken[Maxn];
multiset <int> res;

int Calc(int v, int l)
{
    if (!l) return 1;
    else {
        int res = 0;
        for (int i = v; i <= n; i++)
            for (int j = 0; j < w[i].size(); j++) if (!taken[w[i][j]]) {
                taken[w[i][j]] = true;
                res += Calc(v + 1, l - 1);
                taken[w[i][j]] = false;
            }
        return res;
    }
}

void Gen(int v, int l, int d)
{
    if (!l) {
        if (res.size() < t) res.insert(d);
        else if (d < *res.rbegin()) { res.erase(res.find(*res.rbegin())); res.insert(d); }
    } else for (int i = v; i <= n; i++)
              for (int j = 0; j < w[i].size(); j++) if (!taken[w[i][j]]) {
                  taken[w[i][j]] = true;
                  Gen(i + 1, l - 1, d + r[i][j]);
                  taken[w[i][j]] = false;
              }
}

int main()
{
    scanf("%d %d %d", &n, &k, &t);
    while (k--) {
        int hi, wi, ri; scanf("%d %d %d", &hi, &wi, &ri);
        w[hi].push_back(wi); r[hi].push_back(ri);
    }
    int add = 0;
    int i;
   /* for (i = 0; i <= n; i++) {
        add += Calc(1, i);
        if (t <= add) break;
    }*/
    for (i = n; i >= 0; i--) Gen(1, i, 0);
    printf("%d\n", *res.rbegin());
    return 0;
}