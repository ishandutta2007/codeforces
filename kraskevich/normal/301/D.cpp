#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>


const int N = 300 * 1000;
int p[N], pos[N], n;
vector<int> g[N];
int ans[N];

void init()
{
    for (int x = 1; x <= n; x++)
        for (int to = x; to <= n; to += x)
        {
            int a = pos[to];
            int b = pos[x];
            if (a > b)
                swap(a, b);
            g[b].push_back(a);
        }
}

vector<int> lbod[N];
vector<int> id[N];

template<class Tsum, class Tval>
class fenwickTree
{
    vector<Tval> f;

public:
    void initialize(int n)
    {
        f.assign(n, 0);
    }

    void initialize(vector<Tval> values)
    {
        f.assign(values.size(), 0);
        for (int i = 0; i < f.size(); ++i)
            update(i, values[i]);
    }

    void update(int pos, Tval add)
    {
        for (; pos < f.size(); pos = (pos | (pos + 1)))
            f[pos] += add;
    }

    Tsum getSum(int pos)
    {
        Tsum res = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
            res += (Tsum)f[pos];
        return res;
    }

    Tsum getSum(int L, int R)
    {
        return getSum(R) - getSum(L - 1);
    }
};

fenwickTree<int, int> tree;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        pos[p[i]] = i;


    init();
    tree.initialize(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        cin >> l >> r;
        lbod[r].push_back(l);
        id[r].push_back(i);
    }


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < g[i].size(); ++j)
            tree.update(g[i][j], 1);
        for (int j = 0; j < lbod[i].size(); ++j)
            ans[id[i][j]] = tree.getSum(lbod[i][j], n);
    }


    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";

    return 0;
}