#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int N = 100005;

int n, u;
long long a[N];

struct SNode
{
    pair<int, int> cur;
    int tr;

    SNode(pair<int, int> _cur, int _tr) : cur(_cur), tr(_tr) {}
};
vector<SNode> ve[N / 2];
vector<pair<int, int>> cur;

inline long long sqr(int u) { return 1LL * u * u; };

int main()
{
    scanf("%d", &n);
    ve[0].push_back(SNode(make_pair(0, 0), 0));
    for (int i = 1; i <= n / 2; i++)
    {
        cur.clear();
        scanf("%d", &u);
        for (int i = 1; i * i <= u; i++)
            if (u % i == 0 && (u / i + i) % 2 == 0)
                cur.push_back(make_pair((u / i - i) / 2, (u / i + i) / 2));
        sort(cur.begin(), cur.end());
        int pt = 0;
        for (pair<int, int> &v : cur)
        {
            while (pt < ve[i - 1].size() && ve[i - 1][pt].cur.se < v.fi)
                ++pt;
            if (pt > 0)
                ve[i].push_back(SNode(v, pt - 1));
        }
        sort(ve[i].begin(), ve[i].end(), [](const SNode &a, const SNode &b) { return a.cur.se < b.cur.se; });
    }
    if (ve[n / 2].empty())
        return printf("No"), 0;
    printf("Yes\n");
    for (int i = n, cur = 0; i > 0; i -= 2)
    {
        a[i] = sqr(ve[i / 2][cur].cur.se) - sqr(ve[i / 2][cur].cur.fi);
        a[i - 1] = sqr(ve[i / 2][cur].cur.fi);
        cur = ve[i / 2][cur].tr;
        a[i - 1] -= sqr(ve[i / 2 - 1][cur].cur.se);
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
}