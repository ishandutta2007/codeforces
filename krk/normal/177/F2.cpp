#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 25;

int n, k, t;
vector <int> w[Maxn], r[Maxn];
bool taken[Maxn];
multiset <int> res;

void Gen(int v, int l, int d)
{
    if (res.size() == t && d >= *res.rbegin()) return;
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
    for (int i = 1; i <= n; i++)
        for (int j = int(w[i].size()) - 2; j >= 0; j--)
            for (int k = 0; k <= j; k++)
                if (r[i][k] > r[i][k + 1]) {
                    swap(w[i][k], w[i][k + 1]); swap(r[i][k], r[i][k + 1]);
                }
    for (int i = 0; i <= n; i++) Gen(1, i, 0);
    printf("%d\n", *res.rbegin());
    return 0;
}