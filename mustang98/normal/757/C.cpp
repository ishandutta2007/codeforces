#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100009, mod = 1e9 + 7, max_m = 1000111;

vector<pair<int, int> > v[max_m];
vector<vector<pair<int, int> > > v1;

vector<int> g[max_n];

ll ans = 0;

ll fact(ll a)
{
    if (a == 0 || a == 1) return 1;
    ll ans = 1;
    for (ll i = 2; i<= a; ++i)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

int main()
{
    //ifstream cin("input.txt");
    int k, a, n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j)
        {
            scanf("%d", &a);
            g[i].push_back(a);
        }
        sort(g[i].begin(), g[i].end());

        int klast = 1;
        for (int j = 1; j < k; ++j)
        {
            if (g[i][j] == g[i][j - 1])
            {
                klast++;
            }
            else
            {
                v[g[i][j - 1]].push_back(make_pair(i, klast));
                klast = 1;
            }
        }
        v[g[i][k - 1]].push_back(make_pair(i, klast));
    }

   /* for (int i = 1; i < 5; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j].F <<':'<<v[i][j].S << ' ';
        }
        cout << endl;
    }*/

    int kused = 0;

    for (int i = 1; i <= m; ++i)
    {
        if (v[i].size())
        {
            v1.push_back(v[i]);
            kused++;
        }
    }

    ans = fact(m - kused);


    sort(v1.begin(), v1.end());

    int klast = 1;
    for (int i = 1; i < v1.size(); ++i)
    {
        if (v1[i] == v1[i - 1])
        {
            klast++;
        }
        else
        {
            ans *= fact(klast);
            ans %= mod;
            klast = 1;
        }
    }
    ans *= fact(klast);
    ans %= mod;
    klast = 0;

    cout << ans;

    return 0;
}