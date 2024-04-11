#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 500005;

int n;
vector <ii> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
vector <ii> my[Maxn];
ll res;

void Traverse(int v, int p)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        Traverse(u.first, v);
        my[u.second].push_back(ii(lef[u.first], rig[u.first]));
    }
    rig[v] = cur;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    Traverse(1, 0);
    for (int i = 0; i < Maxn; i++) if (!my[i].empty()) {
        sort(my[i].begin(), my[i].end());
        vector <ii> S;
        vector <int> lft;
        vector <int> add;
        S.push_back(ii(0, n + 1));
        lft.push_back(n);
        add.push_back(0);
        for (int j = 0; j < my[i].size(); j++) {
            ii cur = my[i][j];
            while (S.back().second < cur.first) {
                res += ll(lft.back()) * add.back();
                add.pop_back();
                add.back() += lft.back();
                lft.pop_back();
                S.pop_back();
            }
            int siz = cur.second - cur.first + 1;
            lft.back() -= siz;
            lft.push_back(siz);
            add.push_back(0);
            S.push_back(cur);
        }
        while (!S.empty()) {
            res += ll(lft.back()) * add.back();
            add.pop_back();
            if (!add.empty()) add.back() += lft.back();
            lft.pop_back();
            S.pop_back();
        }
    }
    cout << res << endl;
    return 0;
}