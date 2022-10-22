#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <random>
#include <list>
#include <bitset>

using namespace std;

vector<int> gr[200500];

int par[200500];
int root[200500];
int clr[200500];

int s;

void sol(int t, int u)
{
    vector<int> a = {t};

    while(a.back() != s)
    {
        int y = a.back();
        a.push_back(par[y]);
    }

    vector<int> b = {t,u};



    while(b.back() != s)
    {
        int y = b.back();
        b.push_back(par[y]);
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << "Possible" << endl;

    cout << a.size() << endl;

    for (auto x:a)cout << x << ' '; cout << endl;

    cout << b.size() << endl;

    for (auto x:b)cout << x << ' '; cout << endl;

    exit(0);
}

void dfs(int u, int r)
{
    clr[u] = 1;
    root[u] = r;

    for (auto v:gr[u])
    {
        if (clr[v] == 1)
        {
            assert(root[v] == r);
        } else if (clr[v] == 2) {
            if (root[v] != r)
            {
                sol(v, u);
            }
        } else {
            par[v] = u;
            dfs(v,r);
        }
    }

    clr[u] = 2;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m >> s;

    while(m--)
    {
        int a,b;
        cin >> a >> b;

        if (b == s)
            continue;

        gr[a].push_back(b);

    }

    for (auto x:gr[s])
    {
        if (root[x])
        {
            sol(x, s);
        }
        par[x] = s;
        dfs(x,x);
    }


    cout << "Impossible" << endl;

    return 0;
}