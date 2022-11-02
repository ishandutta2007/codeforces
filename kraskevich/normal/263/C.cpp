#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <cctype>
#include <ctime>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second






const int N = 100 * 1000 + 10;
vector<int> g[N];
vector<bool> used(N, false);
int ans[N];
int n;
vector<pii> want, have;

bool adj(int l, int r)
{
    vector<int>::iterator it = find(g[l].begin(), g[l].end(), r);
    return it >= g[l].begin() && it < g[l].end();
}

void solve()
{
    cin >> n;
    for (int i = 0; i < 2 * n; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        want.push_back(pii(min(a, b), max(a, b)));
    }

    for (int i = 0; i < n; ++i)
    {
        if (g[i].size() != 4)
        {
            cout << -1;
            return;
        }
    }

    sort(want.begin(), want.end());

    for (int v1 = 0; v1 < 4; ++v1)
        for (int v2 = 0; v2 < 4; ++v2)
        {
            if (v1 == v2)
                continue;

            int a = g[0][v1];
            int b = g[0][v2];
            if (!adj(a, b))
                continue;

            fill(used.begin(), used.end(), false);
            have.clear();


            ans[0] = 0;
            ans[1] = a;
            ans[2] = b;
            used[0] = used[a] = used[b] = true;

            bool bad = false;

            for (int i = 3; i < n; ++i)
            {
                int p1 = ans[i - 1];
                int p2 = ans[i - 2];
                int nvertex = -1;

                for (int it1 = 0; it1 < 4; ++it1)
                    for (int it2 = 0; it2 < 4; ++it2)
                    {
                        int v1 = g[p1][it1];
                        int v2 = g[p2][it2];
                        if (used[v1])
                            continue;
                        if (used[v2])
                            continue;
                        if (v1 == v2)
                            nvertex = v1;
                    }

                if (nvertex == -1)
                {
                    bad = true;
                    break;
                }

                ans[i] = nvertex;
                used[nvertex] = true;
            }

            if (bad)
                continue;
            /*for (int i = 0; i < n; ++i)
                cerr << ans[i] + 1 << " ";
            cerr << endl;*/

            for (int i = 0; i < n; ++i)
                for (int j = (i + 1) % n; j != (i + 3) % n; j = (j + 1) % n)
                {
                    //cerr << i << " " << j << endl;
                    have.push_back(pii(min(ans[i], ans[j]), max(ans[i], ans[j])));
                }

            sort(have.begin(), have.end());

            /*for (int i = 0; i < have.size();++i)
                cerr << have[i].F + 1 << " " << have[i].S + 1 << endl;*/


            if (have != want)
                continue;


            for (int i = 0; i < n; ++i)
            {
                cout << ans[i] + 1 << " ";
            }
            return;
        }

    cout << -1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}