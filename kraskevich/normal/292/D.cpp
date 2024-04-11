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

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair


struct Dsu
{
    vector<int> p;

    Dsu() {}

    Dsu(vector<int> _p)
    {
        p = _p;
    }

    Dsu(int size)
    {
        p.resize(size);
        for (int i = 0; i < size; ++i)
            p[i] = i;
    }

    int get(int v)
    {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    void unite(int a, int b)
    {
        a = get(a);
        b = get(b);
        if (a == b)
            return;
        if (rand() & 1)
            swap(a, b);
        p[a] = b;
    }

    int getCount()
    {
        int ans = 0;
        for (int i = 0; i < p.size(); ++i)
        {
            if (p[i] == i)
                ans++;
        }
        return ans;
    }
};

const int M = 10010;
Dsu pref[M];
Dsu suff[M];
Dsu curr;
int n, m;
int from[M];
int to[M];

int getAnswer(int l, int r)
{
    curr = Dsu(n);
    for (int i = 0; i < n; ++i)
        curr.unite(i, pref[l - 1].get(i));
    for (int i = 0; i < n; ++i)
        curr.unite(i, suff[r + 1].get(i));
    for (int i = 0; i < n; ++i)
        curr.unite(pref[l - 1].get(i), suff[r + 1].get(i));
    return curr.getCount();
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> from[i] >> to[i];
        --from[i];
        --to[i];
    }

    pref[0] = Dsu(n);
    suff[m + 1] = Dsu(n);
    for (int i = 1; i <= m; ++i)
    {
        pref[i] = Dsu(pref[i - 1].p);
        pref[i].unite(from[i], to[i]);
    }
    for (int i = m; i >= 1; --i)
    {
        suff[i] = Dsu(suff[i + 1].p);
        suff[i].unite(from[i], to[i]);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << getAnswer(l, r) << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}