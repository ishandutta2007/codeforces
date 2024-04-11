#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E6 + 5, W = 1E6 + 5;

int n, w, k, u;
long long cur = 0;
multiset<int, greater<int>> se[N];

struct SEvent
{
    int ind, val;
    bool typ;

    SEvent(int _ind, int _val, bool _typ)
    {
        ind = _ind;
        val = _val;
        typ = _typ;
    }
};
vector<SEvent> eve[W];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> u;
            eve[j].push_back(SEvent(i, u, true));
            eve[w - k + j + 1].push_back(SEvent(i, u, false));
        }
        eve[1].push_back(SEvent(i, 0, true));
        eve[w - k + 1].push_back(SEvent(i, 0, false));
        eve[k + 1].push_back(SEvent(i, 0, true));
        eve[w + 1].push_back(SEvent(i, 0, false));
    }
    for (int i = 1; i <= w; i++)
    {
        for (SEvent &v : eve[i])
            if (v.typ)
            {
                if (!se[v.ind].empty())
                    cur -= *se[v.ind].begin();
                se[v.ind].insert(v.val);
                cur += *se[v.ind].begin();
            }
            else
            {
                cur -= *se[v.ind].begin();
                se[v.ind].erase(se[v.ind].find(v.val));
                if (!se[v.ind].empty())
                    cur += *se[v.ind].begin();
            }
        cout << cur << " ";
    }
}